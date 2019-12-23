#include "stdafx.h"
#include "..\xrRender\xrRender_console.h"



void CRenderTarget::phase_motion_blur()
{
	Fmatrix		m_previous, m_current;
	Fvector2	m_blur_scale;
	{
		static Fmatrix		m_saved_viewproj;

		// (new-camera) -> (world) -> (old_viewproj)
		Fmatrix	m_invview;	m_invview.invert(Device.mView);
		m_previous.mul(m_saved_viewproj, m_invview);
		m_current.set(Device.mProject);
		m_saved_viewproj.set(Device.mFullTransform);
		float	scale = ps_r2_mblur / 2.f;
		m_blur_scale.set(scale, -scale).div(12.f);
	}

	u32 Offset;

	// Draw COLOR
	prepare_simple_quad			(rt_mblur, s_mblur->E[0], Offset, 1.0f);
	RCache.set_c				("m_current",	m_current);
	RCache.set_c				("m_previous",	m_previous);
	RCache.set_c				("m_blur",		m_blur_scale.x,m_blur_scale.y, 0,0);
	RCache.Render				(D3DPT_TRIANGLELIST,Offset,0,4,0,2);
	render_simple_quad			(rt_Generic_0,	s_mblur->E[1], 1.0);	
};