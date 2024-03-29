#include "stdafx.h"


#include "blender_ssao.h"

CBlender_ssao::CBlender_ssao	()	{	description.CLS		= 0;	}
CBlender_ssao::~CBlender_ssao	()	{	}
 
void	CBlender_ssao::Compile(CBlender_Compile& C)
{
	IBlender::Compile		(C);

	switch (C.iElement)
	{
	case 0:
		C.r_Pass			("null",			"ambient_occlusion",		FALSE,	FALSE,	FALSE);
		C.r_Sampler_rtf		("s_position",		r2_RT_P				);
		C.r_Sampler_rtf		("s_normal",		r2_RT_N				);
		C.r_Sampler_rtf		("s_diffuse",		r2_RT_albedo		);
		C.r_End				();
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		break;
	}
}