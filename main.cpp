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

	//	掛け算

	int x = uniform_int_distribution<>(1, 300)(rand);
	int y = uniform_int_distribution<>(1, 200)(rand);
	questions[0].q = to_string(x) + "x" + to_string(y);
	questions[0].a = x * y;

	//	割り算
	x = uniform_int_distribution<>(1, 300)(rand);
	y = uniform_int_distribution<>(1, 200)(rand);
	questions[1].q = to_string(x * y) + "÷" + to_string(y);
	questions[1].a = x;

	//	複雑な式
	x = uniform_int_distribution<>(1, 1000)(rand);
	y = uniform_int_distribution<>(1, 100)(rand);
	int z = uniform_int_distribution<>(1, 100)(rand);
	int w = uniform_int_distribution<>(1, 100)(rand);
	questions[2].q =
		to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")÷" + to_string(w);
	questions[2].a = x - (y + z);

	//	累乗
	x = uniform_int_distribution<>(2, 50)(rand);
	y = uniform_int_distribution<>(2, 5)(rand);
	questions[3].q = to_string(x) + "^" + to_string(y);
	questions[3].a = static_cast<int>(pow(x, y));

	cout << "[リクルート試験対策クイズ]\n";

	for (const auto& e : questions)
	{
		cout << e.q << "答えは？\n";
		int answer;
		cin >> answer;
		if (answer == e.a)
		{
			cout << "正解\n";
		}
		else
		{
			cout << "間違い！ 正解は" << e.a << "\n";
		}
	}	//	for question

	return	0;
}