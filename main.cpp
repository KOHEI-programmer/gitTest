#include"question.h"
#include"exam_japanese.h"
#include"exam_english.h"
#include"exam_science.h"
#include<iostream>
#include<string>
#include<vector>
#include<random>
using namespace std;

//	�ő���񐔂����߂�
int gcd(int a, int b)
{
	//	�]�肪0�ɂȂ������̏�����Ԃ�
	while (b)
	{
		int r = a % b;
		a = b;		//	���������̔폜���ɂ���
		b = r;		//	�]������̏����ɂ���
	}
	return	a;
}

int main()
{
	vector<Question> questions(4);

	random_device rd;
	mt19937 rand(rd());

	//	�|���Z

	int x = uniform_int_distribution<>(1, 300)(rand);
	int y = uniform_int_distribution<>(1, 200)(rand);
	questions[0].q = to_string(x) + "x" + to_string(y) + "�̓����́H";
	questions[0].a = to_string(x * y);

	//	����Z
	x = uniform_int_distribution<>(1, 300)(rand);
	y = uniform_int_distribution<>(1, 200)(rand);
	questions[1].q = to_string(x * y) + "��" + to_string(y) + "�̓����́H";
	questions[1].a = to_string(x);

	//	���G�Ȏ�
	x = uniform_int_distribution<>(1, 1000)(rand);
	y = uniform_int_distribution<>(1, 100)(rand);
	int z = uniform_int_distribution<>(1, 100)(rand);
	int w = uniform_int_distribution<>(1, 100)(rand);
	questions[2].q =
		to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")��" + to_string(w) + "�̓����́H";
	questions[2].a = to_string(x - (y + z));

	//	�ݏ�
	x = uniform_int_distribution<>(2, 50)(rand);
	y = uniform_int_distribution<>(2, 5)(rand);
	questions[3].q = to_string(x) + "^" + to_string(y) + "�̓����́H";
	questions[3].a = to_string(static_cast<int>(pow(x, y)));

	//	�O�p�`�̖ʐ�
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 50)(rand) * 2;
	questions.push_back({"�ʐ�" + to_string(x * y / 2) + "cm^2�A���" + to_string(y) + "cm�̎O�p�`�̍��������߂�B",to_string(x)});

	//	�~���̑̐�
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 50)(rand) * 3;
	questions.push_back({ "��ʂ̔��a" + to_string(x) + "cm�A����" + to_string(y) + "cm�̉~��������B\n" +
		"���̉~���̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�B",to_string(x * x * y / 3) });

	//	���̑̐�
	x = uniform_int_distribution<>(1, 50)(rand);
	questions.push_back({"���a" + to_string(x) + "cm�̋�������B\n" + "���̋��̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�B",to_string(4 * x * x * x / 3) });

	//	��������̊m��
	x = uniform_int_distribution<>(1, 5)(rand);
	y = uniform_int_distribution<>(1, 6 - x)(rand);
	z = gcd(y + 1, 6);
	questions.push_back({ "�T�C�R����1�U����" + to_string(x) + "����" + to_string(x + y) + "���o��m�������߂�B",
		to_string((y + 1) / z) + "/" + to_string(6 / z) });

	//	����
	x = uniform_int_distribution<>(3, 7)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++)
	{
		z *= x - i;
	}
	questions.push_back({ to_string(x) + "�l�̂���" + to_string(y) + "�l��I��ŕ��ׂ���@�͉��ʂ肠�邩�H",to_string(z) });

	//	�g�ݍ��킹
	x = uniform_int_distribution<>(3, 6)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++)
	{
		z *= x - i;
	}
	for (int i = 0; i < y; i++)
	{
		z /= y - i;
	}
	questions.push_back({ to_string(x) + "�l�̂���" + to_string(y) + "�l��I��ŕ��ׂ���@�͉��ʂ肠�邩�H",to_string(z) });

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	cout << "���Ȃ�I��ł�������\n1=���w\n2=����\n3=�p��\n4=����";
	int subject;
	cin >> subject;
	if (subject == 2)
	{
		questions = CreateKanjiExam();
		const QuestionList idiomExam = CreateIdiomExam();
		questions.insert(questions.end(), idiomExam.begin(), idiomExam.end());
		const QuestionList homophoneExam = CreateHomophoneExam();
		questions.insert(questions.end(), homophoneExam.begin(), homophoneExam.end());
		const QuestionList antonymExam = CreateAntonymExam();
		questions.insert(questions.end(), antonymExam.begin(), antonymExam.end());
		const QuestionList synonymExam = CreateSynonymExam();
		questions.insert(questions.end(), synonymExam.begin(), synonymExam.end());
	}
	else if (subject == 3)
	{
		questions = CreateEnglishWordExam();
		QuestionList phraseExam = CreateEnglishPhraseExam();
		questions.insert(questions.end(), phraseExam.begin(), phraseExam.end());
	}
	else if (subject == 4)
	{
		questions = CreatePhysicsExam();
	}

	for (const auto& e : questions)
	{
		cout << e.q << "\n";
		string answer;
		cin >> answer;
		if (answer == e.a)
		{
			cout << "����\n";
		}
		else
		{
			cout << "�ԈႢ�I ������" << e.a << "\n";
		}
	}	//	for question

	return	0;
}