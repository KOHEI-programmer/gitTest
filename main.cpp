#include"question.h"
#include"exam_japanese.h"
#include<iostream>
#include<string>
#include<vector>
#include<random>
using namespace std;

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

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	cout << "���Ȃ�I��ł�������\n1=���w\n2=����\n";
	int subject;
	cin >> subject;
	if (subject == 2)
	{
		questions = CreateKanjiExam();
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