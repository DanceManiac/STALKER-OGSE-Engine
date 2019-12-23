#include "stdafx.h"
#include "..\xrRender\xrRender_console.h"

void CRenderTarget::phase_sunshafts()
{
	CEnvDescriptorMixer *env = &(g_pGamePersistent->Environment().CurrentEnv);
	if (env->sun_shafts <= 0.001) return;
	u32 Offset;

	// constants

	Fvector4 params = {0,0,0,0};
	params.x = env->sun_shafts;
	params.y = env->sun_shafts_length;

//mask
	render_simple_quad(rt_sunshafts_0,	s_sunshafts->E[0], 1.0);

//1st pass	
	params.z = 1.0;
	render_simple_quad(rt_sunshafts_1,	s_sunshafts->E[1], 1.0);
	RCache.set_c				("c_sunshafts",	params);
//2nd pass
	params.z = 0.7;
	render_simple_quad(rt_sunshafts_0,	s_sunshafts->E[2], 1.0);
	RCache.set_c				("c_sunshafts",	params);
//3rd pass
	params.z = 0.3;
	render_simple_quad(rt_sunshafts_1,	s_sunshafts->E[3], 1.0);
	RCache.set_c				("c_sunshafts",	params);

//render
	params.z = 0.0;	
	render_simple_quad(rt_Generic_0,	s_sunshafts->E[4], 1.0);	
	RCache.set_c				("c_sunshafts",	params);
	
	RCache.Render				(D3DPT_TRIANGLELIST,Offset,0,4,0,2);
};