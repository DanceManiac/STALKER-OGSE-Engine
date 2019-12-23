#include "stdafx.h"


#include "blender_mblur.h"

CBlender_mblur::CBlender_mblur	()	{	description.CLS		= 0;	}
CBlender_mblur::~CBlender_mblur	()	{	}
 
void	CBlender_mblur::Compile(CBlender_Compile& C)
{
	IBlender::Compile		(C);

	switch (C.iElement)
	{
	case 0:	// mblur
		C.r_Pass			("null",			"motion_blur",		FALSE,	FALSE,	FALSE);
		C.r_Sampler_rtf		("s_position",		r2_RT_P);
		C.r_Sampler_clf		("s_current",		r2_RT_generic0);
		C.r_End				();
		break;
	case 1:
		C.r_Pass("null", "ogse_apply_postprocess", FALSE, FALSE, FALSE, TRUE, D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
		C.r_Sampler_clf		("s_pp",			r2_RT_mblur);
		C.r_End				();
		break;
	}
}