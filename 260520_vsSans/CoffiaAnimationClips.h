#pragma once
#include "Animation.h"

class CoffiaAnimationClips
{
public:
	static AnimationClip TestClip();

	// 기본
	static AnimationClip Idle_Clip();
	static AnimationClip Idle_ChinRest_Clip();

	// 손인사
	static AnimationClip Greeting_Clip();
	static AnimationClip Greeting_SmilingEyes_Clip();

	// 꾸벅인사
	static AnimationClip BowGreeting_Clip();
	static AnimationClip BowGreeting_Happy_Clip();

	// 고개 돌리기
	static AnimationClip LookRight_Clip();
	static AnimationClip LookLeft_Clip();

	// 대화
	static AnimationClip Talk_Clip();
	static AnimationClip Talk_Happy_Clip();
	static AnimationClip Talk_Angry_Clip();
	static AnimationClip Talk_LowEnergy_Clip();

	// 턱 괴고 대화
	static AnimationClip Talk_ChinRest_Clip();
	static AnimationClip Talk_ChinRest_Happy_Clip();
	static AnimationClip Talk_ChinRest_Angry_Clip();
	static AnimationClip Talk_ChinRest_LowEnergy_Clip();
};

