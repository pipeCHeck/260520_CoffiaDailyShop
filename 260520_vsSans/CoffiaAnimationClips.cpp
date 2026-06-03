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

AnimationClip CoffiaAnimationClips::ChinRest_Clip()
{
	AnimationClip clip;
	clip.SetName("ChinRest_Clip");
	clip.SetIsLooping(false);

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "ArmL", Vector2f(0, -49), 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(35, "ArmL", Vector2f(-47, -13), 15, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(50, "ArmL", Vector2f(-47, -15), 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(60, "ArmL", Vector2f(-49, -12.498f), 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "ArmL", 66, 0, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "ArmL", -5, 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(35, "ArmL", 2, 15, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(50, "ArmL", 1, 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(60, "ArmL", 2, 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "HandL", 0));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "HandL_Line", 1));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HandL", 0, 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(35, "HandL", 4, 15, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(50, "HandL", 3, 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(60, "HandL", 0, 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "Mouth", 1));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(50, "Mouth", 2));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "Mouth", Vector2f(0, -6), 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(35, "Mouth", Vector2f(0, 0), 17, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "Nose", Vector2f(0, -18.5f), 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(35, "Nose", Vector2f(0, 11), 17, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(52, "Nose", Vector2f(0, 5), 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(62, "Nose", Vector2f(0, 6.964f), 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(72, "Nose", Vector2f(0, 5.981f), 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(5, "HairF_SideL", -3, 36.875f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(41.875f, "HairF_SideL", 5, 22.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(64.5f, "HairF_SideL", 2, 11, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(75.5f, "HairF_SideL", 3, 11, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(5, "HairF_SideR", 3, 36.875f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(41.875f, "HairF_SideR", 0, 22.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(64.5f, "HairF_SideR", 1, 11, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(75.5f, "HairF_SideR", 0, 11, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairF_Bang", 9, 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(35, "HairF_Bang", -6, 19, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(54, "HairF_Bang", 3, 16.4453f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(70.4453f, "HairF_Bang", 0, 16.5547f, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeScaleKeyFrame(0, "HairF", Vector2f(1, 0.86f), 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(35, "HairF", Vector2f(1, 1.08f), 22.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(57.625f, "HairF", Vector2f(1, 1.05f), 11, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(68.625f, "HairF", Vector2f(1, 1.06f), 11, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(5, "HairSideL_1", -9, 39.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(44.625f, "HairSideL_1", 2, 22.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(67.25f, "HairSideL_1", -1, 11, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(78.25f, "HairSideL_1", 1, 11, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(5, "HairSideL_2", -9, 44.375f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(49.375f, "HairSideL_2", 2, 20.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(70, "HairSideL_2", -1, 11, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(81, "HairSideL_2", 1, 11, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(5, "HairSideR_1", 4, 39.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(44.625f, "HairSideR_1", 0, 22.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(67.25f, "HairSideR_1", 2, 11, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(78.25f, "HairSideR_1", 0, 11, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(5, "HairSideR_2", 5, 44.375f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(49.375f, "HairSideR_2", 0, 20.625f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(70, "HairSideR_2", 2, 11, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(81, "HairSideR_2", 0, 11, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(35, "Face", Vector2f(0, 10), 17, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(52, "Face", Vector2f(0, 7), 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(62, "Face", Vector2f(0, 7.982f), 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "Body", Vector2f(0, -13), 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(35, "Body", Vector2f(36, 42), 17, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(52, "Body", Vector2f(35, 41), 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(62, "Body", Vector2f(33, 43), 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Body", 2, 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(35, "Body", -7, 17, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(52, "Body", -6.7f, 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(62, "Body", -7, 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Hair_AhogeL", -15, 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(35, "Hair_AhogeL", 15, 17, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(52, "Hair_AhogeL", 7.5f, 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(62, "Hair_AhogeL", 0, 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "Hair_AhogeR", 12, 35, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(35, "Hair_AhogeR", -12, 17, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(52, "Hair_AhogeR", -6, 10, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(62, "Hair_AhogeR", 0, 10, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairB_HeadL", -2, 42, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(42, "HairB_HeadL", 0, 26, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(68, "HairB_HeadL", -1, 13, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(81, "HairB_HeadL", 0.3f, 12, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(93, "HairB_HeadL", 0, 12, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairB_HeadR", 2, 42, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(42, "HairB_HeadR", 0, 26, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(68, "HairB_HeadR", 1, 13, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(81, "HairB_HeadR", -0.3f, 12, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(93, "HairB_HeadR", 0, 12, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairB_Head_SideTuftL", -4, 42, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(42, "HairB_Head_SideTuftL", 2, 26, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(68, "HairB_Head_SideTuftL", -0.5f, 13, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(81, "HairB_Head_SideTuftL", 0.2f, 12, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(93, "HairB_Head_SideTuftL", 0, 12, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairB_Head_SideTuftR", 4, 42, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(42, "HairB_Head_SideTuftR", -2, 26, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(68, "HairB_Head_SideTuftR", 0.5f, 13, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(81, "HairB_Head_SideTuftR", -0.2f, 12, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(93, "HairB_Head_SideTuftR", 0, 12, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairBL", -1, 42, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(42, "HairBL", 3, 25.9473f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(67.9473f, "HairBL", 0, 12.7715f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(80.7188f, "HairBL", 2, 12.7714f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(93.4902f, "HairBL", 1.27913f, 11.5098f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(105, "HairBL", 1.54688f, 12, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeRotationKeyFrame(0, "HairBR", 1, 42, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(42, "HairBR", -1, 25.9473f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(67.9473f, "HairBR", 1, 12.7715f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(80.7188f, "HairBR", 0, 12.7714f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(93.4902f, "HairBR", 0.360436f, 11.5098f, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeRotationKeyFrame(105, "HairBR", 0.226562f, 12, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "EyeL_Brow", Vector2f(0, -7), 45, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(45, "EyeL_Brow", Vector2f(0, 8), 5, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(50, "EyeL_Brow", Vector2f(0, 0), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(50, "EyeL_Pupil", 1));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(50, "EyeL_Lid", 1));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeL_Pupil", 0));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeL_Lid", 0));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "EyeL_Lid", Vector2f(0, -5), 45, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(45, "EyeL_Lid", Vector2f(0, 16), 5, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(50, "EyeL_Lid", Vector2f(0, 0), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeScaleKeyFrame(0, "EyeL_White", Vector2f(1, 1.24f), 45, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(45, "EyeL_White", Vector2f(1, 0.2f), 5, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(50, "EyeL_White", Vector2f(1, 1.02f), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "EyeR_Brow", Vector2f(0, -7), 45, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(45, "EyeR_Brow", Vector2f(0, 8), 5, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(50, "EyeR_Brow", Vector2f(0, 0), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(50, "EyeR_Pupil", 1));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(50, "EyeR_Lid", 1));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeR_Pupil", 0));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeR_Lid", 0));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(0, "EyeR_Lid", Vector2f(0, -5), 45, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(45, "EyeR_Lid", Vector2f(0, 16), 5, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakePositionKeyFrame(50, "EyeR_Lid", Vector2f(0, 0), 16, EaseType::EaseInOut));

	clip.AddKeyFrame(clip.MakeScaleKeyFrame(0, "EyeR_White", Vector2f(1, 1.24f), 45, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(45, "EyeR_White", Vector2f(1, 0.2f), 5, EaseType::EaseInOut));
	clip.AddKeyFrame(clip.MakeScaleKeyFrame(50, "EyeR_White", Vector2f(1, 1.02f), 16, EaseType::EaseInOut));



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

	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeL_Pupil", 0));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeL_Lid", 0));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeR_Pupil", 0));
	clip.AddKeyFrame(clip.MakeSpriteKeyFrame(0, "EyeR_Lid", 0));

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