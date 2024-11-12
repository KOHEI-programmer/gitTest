#include"exam_science.h"
#include"utility.h"
#include<random>
using namespace std;

/*
* 	�����̖����쐬����
*/
QuestionList CreatePhysicsExam()
{
	QuestionList questions;
	questions.reserve(10);
	random_device rd;

	{
		//	���������^��
		constexpr int divisors[] = { 1,2,3,4,5,10,12,15,20,30,60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i];	//	����
		int t = uniform_int_distribution<>(1, 10)(rd) * divisors[i];		//	����
		questions.push_back({ "����" + to_string(v) + "km�ňړ�����Ԃ�����B\n���̎Ԃ�" +
			to_string(v * t / 60) + "km�ړ�����̂ɂ����鎞�Ԃ𕪒P�ʂŋ��߂�" , to_string(t) });

		i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i];	//	����
		t = uniform_int_distribution<>(1, 10)(rd) * divisors[i];		//	����
		questions.push_back({ "����Ԃ�" + to_string(v * t / 60) + "km���ꂽ�n�_�܂ňړ�����̂�" +
			to_string(t) + "�����������B\n���̎Ԃ̕��ώ��������߂�",to_string(v) });
	}	//	���������^��

	{
		//	�������x�����^��
		//	�����Fv = v0 + at ���g���ĉ������
		int v0 = uniform_int_distribution<>(1, 10)(rd);	//	����
		int a = uniform_int_distribution<>(1, 5)(rd);	//	����
		int t = uniform_int_distribution<>(1, 10)(rd);	//	����
		questions.push_back({ "�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��A�i�s�����ɑ傫��" +
			to_string(a) + "m/s�œ������x�����^�����n�߂��B\n" + to_string(t) + "�b��̑��x��m/s�P�ʂŋ��߂�B",
			to_string(v0 + a * t) });

		//	�����Fx = v0t + 1/2*at^2 ���g���ĉ������
		v0 = uniform_int_distribution<>(5, 20)(rd);		//	����
		a = uniform_int_distribution<>(1, 5)(rd) * 2;	//	����
		t = uniform_int_distribution<>(1, 10)(rd);		//	����
		questions.push_back({ "�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��A�i�s�����ɑ傫��" +
			to_string(a) + "m/s�œ������x�����^�����n�߂��B\n�������n�߂Ă���" +
			to_string(t) + "�b��܂łɈړ�����������m�P�ʂŋ��߂�B",to_string(v0 * t + a * t * t / 2) });

		//	�����Fv^2 -vo^2 = 2ax ���g���ĉ������
		a = -uniform_int_distribution<>(1, 5)(rd) * 2;	//	����
		t = uniform_int_distribution<>(1, 10)(rd);		//	����
		v0 = -a * t;									//	����
		questions.push_back({ "�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��u���[�L���������Ƃ���A" +
			to_string(v0 * t + a * t * t / 2) + "m�i��Œ�~�����B\n�u���[�L�̉����x��m/s^2�P�ʂŋ��߂�",
			to_string(a) });
	}	//	�������x�����^��
	return	questions;
}