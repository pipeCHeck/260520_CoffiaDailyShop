#include "CoffiaAnimationClips.h"

AnimationClip CoffiaAnimationClips::TestClip()
{
	AnimationClip clip;
	clip.SetName("TestClip");
	clip.SetIsLooping(true);

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "Head", Vector2f(0, 0), Vector2f(100, 100), 1, EaseType::Linear));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Head", 0, 720, 2, EaseType::Linear));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(0, "Head", Vector2f(1, 1), Vector2f(2, 2), 1, EaseType::Linear));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(1, "Head", Vector2f(100, 100), Vector2f(-100, 50), 1, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(2, "Head", Vector2f(-100, 50), Vector2f(100, 50), 1, EaseType::EaseOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(2, "Head", 0, -180, 1, EaseType::EaseOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(1, "Head", Vector2f(100, 100), Vector2f(-100, 50), 1, EaseType::EaseIn));

	return clip;
}
// 기본
AnimationClip CoffiaAnimationClips::Idle_Clip()
{
	AnimationClip clip;
	clip.SetName("Idle_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::Idle_ChinRest_Clip()
{
	AnimationClip clip;
	clip.SetName("Idle_ChinRest_Clip");
	clip.SetIsLooping(false);

	return clip;
}

// 손인사
AnimationClip CoffiaAnimationClips::Greeting_Clip()
{
	AnimationClip clip;
	clip.SetName("Greeting_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::CoffiaAnimationClips::Greeting_SmilingEyes_Clip()
{
	AnimationClip clip;
	clip.SetName("Greeting_SmilingEyes_Clip");
	clip.SetIsLooping(true);

	clip.AddKeyFrame(clip.MakeActiveKeyFrame(0, "ArmL", true));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "ArmL", -135, 0, EaseType::Linear));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "ArmL", -15, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(20, "ArmL", -40, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(40, "ArmL", -22.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(60, "ArmL", -33.75f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(80, "ArmL", -32.8377f, 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "ArmL", -123, 40, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "ArmL", Vector2f(0, 0), 0, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "ArmL", Vector2f(20, -17), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(20, "ArmL", Vector2f(9, 0), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(40, "ArmL", Vector2f(16.7f, -8), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(60, "ArmL", Vector2f(12.3, 0), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(80, "ArmL", Vector2f(12.7, -0.7), 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(110, "ArmL", Vector2f(15, 16.5), 40, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "HandL", 2));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "HandL_Line", 3));
	clip.AddKeyFrame(clip.MakeActiveKeyFrame(0, "HandL", true));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HandL", 20, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(20, "HandL", -10, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(40, "HandL", 5, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(60, "HandL", -2, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "HandL", 7, 40, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Body", -0.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(20, "Body", 0.3f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(40, "Body", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "Body", -0.5f, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "Body", 0.2f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "Body", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "Body", Vector2f(0, -14), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(21, "Body", Vector2f(0, 4), 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(51, "Body", Vector2f(0, 0), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(110, "Body", Vector2f(0, 7), 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(140, "Body", Vector2f(0, -4), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(160, "Body", Vector2f(0, 0), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "Nose", Vector2f(0, -10), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(20, "Nose", Vector2f(0, 11), 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(50, "Nose", Vector2f(0, 0), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(110, "Nose", Vector2f(0, 3.5f), 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(140, "Nose", Vector2f(0, -2.5f), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(160, "Nose", Vector2f(0, 0), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairF_SideL", -3, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(21, "HairF_SideL", 1, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(51, "HairF_SideL", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "HairF_SideL", 2, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "HairF_SideL", -0.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "HairF_SideL", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairF_SideR", 3, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(21, "HairF_SideR", -1, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(51, "HairF_SideR", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "HairF_SideR", -2, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "HairF_SideR", 0.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "HairF_SideR", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairF_Bang", 12, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(21, "HairF_Bang", -5, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(51, "HairF_Bang", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "HairF_Bang", 5, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "HairF_Bang", -2, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "HairF_Bang", 0.5f, 16, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(176, "HairF_Bang", 0, 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeScaleKeyFrame(0, "HairF", Vector2f(1, 0.95f), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(21, "HairF", Vector2f(1, 1.08f), 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(51, "HairF", Vector2f(1, 1), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(110, "HairF", Vector2f(1, 1.02f), 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(140, "HairF", Vector2f(1, 0.98f), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(160, "HairF", Vector2f(1, 1), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairSideL_1", 2, 61, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(61, "HairSideL_1", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(120, "HairSideL_1", 2, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(150, "HairSideL_1", -0.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(170, "HairSideL_1", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairSideL_2", 2, 74, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(74, "HairSideL_2", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(130, "HairSideL_2", 2, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "HairSideL_2", -0.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(180, "HairSideL_2", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairSideR_1", -2, 61, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(61, "HairSideR_1", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(120, "HairSideR_1", -2, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(150, "HairSideR_1", 0.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(170, "HairSideR_1", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairSideR_2", -1, 74, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(74, "HairSideR_2", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(130, "HairSideR_2", -2, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "HairSideR_2", 0.5f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(180, "HairSideR_2", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Body_ArmL", -3, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(20, "Body_ArmL", 2, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(40, "Body_ArmL", -3, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(60, "Body_ArmL", 0.25f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(80, "Body_ArmL", 0.005457f, 15, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(95, "Body_ArmL", 0.004346f, 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(105, "Body_ArmL", -5, 40, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(145, "Body_ArmL", 1, 25, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(170, "Body_ArmL", 0.004346f, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Hair_AhogeL", -20, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(21, "Hair_AhogeL", 10, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(51, "Hair_AhogeL", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "Hair_AhogeL", 6, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "Hair_AhogeL", -2, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "Hair_AhogeL", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Hair_AhogeR", 20, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(21, "Hair_AhogeR", -10, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(51, "Hair_AhogeR", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "Hair_AhogeR", -6, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "Hair_AhogeR", 2, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "Hair_AhogeR", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairB_HeadL", -2, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(21, "HairB_HeadL", 0.5f, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(51, "HairB_HeadL", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "HairB_HeadL", 1, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "HairB_HeadL", -0.3f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "HairB_HeadL", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairB_HeadR", 2, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(21, "HairB_HeadR", 0.5f, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(51, "HairB_HeadR", 0, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(110, "HairB_HeadR", -1, 30, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(140, "HairB_HeadR", 0.3f, 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(160, "HairB_HeadR", 0, 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "EyeL_Lid", Vector2f(0, 20.375f), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(110, "EyeL_Lid", Vector2f(0, 0), 30, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeScaleKeyFrame(0, "EyeL_White", Vector2f(1, 0), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(110, "EyeL_White", Vector2f(1, 1), 30, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "EyeR_Lid", Vector2f(0, 20.375f), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(110, "EyeR_Lid", Vector2f(0, 0), 30, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeScaleKeyFrame(0, "EyeR_White", Vector2f(1, 0), 20, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(110, "EyeR_White", Vector2f(1, 1), 30, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "Mouth", 2));

	return clip;
}	

// 꾸벅인사
AnimationClip CoffiaAnimationClips::BowGreeting_Clip()
{
	AnimationClip clip;
	clip.SetName("BowGreeting_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::BowGreeting_Happy_Clip()
{
	AnimationClip clip;
	clip.SetName("BowGreeting_Happy_Clip");
	clip.SetIsLooping(false);

	return clip;
}

// 고개 돌리기
AnimationClip CoffiaAnimationClips::LookRight_Clip()
{
	AnimationClip clip;
	clip.SetName("LookRight_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::LookLeft_Clip()
{
	AnimationClip clip;
	clip.SetName("LookLeft_Clip");
	clip.SetIsLooping(false);

	return clip;
}

// 대화
AnimationClip CoffiaAnimationClips::Talk_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::Talk_Happy_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_Happy_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::Talk_Angry_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_Angry_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::Talk_LowEnergy_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_LowEnergy_Clip");
	clip.SetIsLooping(false);

	return clip;
}

// 턱 괴고 대화
AnimationClip CoffiaAnimationClips::Talk_ChinRest_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_ChinRest_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::Talk_ChinRest_Happy_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_ChinRest_Happy_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::Talk_ChinRest_Angry_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_ChinRest_Angry_Clip");
	clip.SetIsLooping(false);

	return clip;
}

AnimationClip CoffiaAnimationClips::Talk_ChinRest_LowEnergy_Clip()
{
	AnimationClip clip;
	clip.SetName("Talk_ChinRest_LowEnergy_Clip");
	clip.SetIsLooping(false);

	return clip;
}