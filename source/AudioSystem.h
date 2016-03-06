#pragma once
#include<AL\ALDevice.h>
namespace AudioSystem {
	extern ALDevice Device;
	//Gain
	extern ALfloat BGMGain;//��������
	extern ALfloat SoundGain;//��Ч
	//Set
	extern ALenum DopplerModel;//����OpenAL�ľ���ģ��
	extern ALfloat DopplerFactor;//����������
	extern ALfloat SpeedOfSound;//����
	const ALfloat Air_SpeedOfSound = 343.3f;
	const ALfloat Water_SpeedOfSound = 1473.0f;
	void Init();
	void Update(ALfloat PlayerPos[3],bool BFall, bool BBlockClick, ALfloat BlockPos[3], int Run, bool BDownWater);
	void ClickEvent();
	void GUIUpdate();
	void UnInit();
}