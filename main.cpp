#include"question.h"
#include<iostream>
#include<string>
#include<random>
using namespace std;

int main()
{
	Question questions[4];

	random_device rd;
	mt19937 rand(rd());

	//	�|���Z

	int x = uniform_int_distribution<>(1, 300)(rand);
	int y = uniform_int_distribution<>(1, 200)(rand);
	questions[0].q = to_string(x) + "x" + to_string(y);
	questions[0].a = x * y;

	//	����Z
	x = uniform_int_distribution<>(1, 300)(rand);
	y = uniform_int_distribution<>(1, 200)(rand);
	questions[1].q = to_string(x * y) + "��" + to_string(y);
	questions[1].a = x;

	//	���G�Ȏ�
	x = uniform_int_distribution<>(1, 1000)(rand);
	y = uniform_int_distribution<>(1, 100)(rand);
	int z = uniform_int_distribution<>(1, 100)(rand);
	int w = uniform_int_distribution<>(1, 100)(rand);
	questions[2].q =
		to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")��" + to_string(w);
	questions[2].a = x - (y + z);

	//	�ݏ�
	x = uniform_int_distribution<>(2, 50)(rand);
	y = uniform_int_distribution<>(2, 5)(rand);
	questions[3].q = to_string(x) + "^" + to_string(y);
	questions[3].a = static_cast<int>(pow(x, y));

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	for (const auto& e : questions)
	{
		cout << e.q << "�����́H\n";
		int answer;
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