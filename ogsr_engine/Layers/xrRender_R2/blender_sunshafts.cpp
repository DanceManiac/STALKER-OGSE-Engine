#include "stdafx.h"


#include "blender_sunshafts.h"

CBlender_sunshafts::CBlender_sunshafts	()	{	description.CLS		= 0;	}
CBlender_sunshafts::~CBlender_sunshafts	()	{	}
 
void	CBlender_sunshafts::Compile(CBlender_Compile& C)
{
	IBlender::Compile		(C);

	switch (C.iElement)
	{
	case 0:	// generation of sunshafts mask
		C.r_Pass			("null",			"sunshafts_mask",		FALSE,	FALSE,	FALSE);
		C.r_Sampler_rtf		("s_position",		r2_RT_P				);
		C.r_Sampler_clf		("s_image",			r2_RT_generic0);
		C.r_End				();
		break;
	case 1:	// first pass
		C.r_Pass			("null",			"sunshafts_blur",	FALSE,	FALSE,	FALSE);
		C.r_Sampler_clf		("s_sun_shafts",		r2_RT_sunshafts0);
		C.r_End				();
		break;
	case 2:	// second pass
		C.r_Pass			("null",			"sunshafts_blur",	FALSE,	FALSE,	FALSE);
		C.r_Sampler_clf		("s_sun_shafts",		r2_RT_sunshafts1);
		C.r_End				();
		break;
	case 3:	// third pass
		C.r_Pass			("null",			"sunshafts_blur",	FALSE,	FALSE,	FALSE);
		C.r_Sampler_clf		("s_sun_shafts",		r2_RT_sunshafts0);
		C.r_End				();
		break;
	case 4:	// combine pass
		C.r_Pass			("null",			"sunshafts_final",	FALSE,	FALSE,	FALSE);
		C.r_Sampler_rtf		("s_position",		r2_RT_P				);
		C.r_Sampler_clf		("s_sun_shafts",	r2_RT_sunshafts1);
		C.r_Sampler_clf		("s_image",			r2_RT_generic0);
		jitter(C);
		C.r_End				();
		break;
	}
}