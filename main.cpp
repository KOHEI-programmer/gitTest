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

	//	掛け算

	int x = uniform_int_distribution<>(1, 300)(rand);
	int y = uniform_int_distribution<>(1, 200)(rand);
	questions[0].q = to_string(x) + "x" + to_string(y) + "の答えは？";
	questions[0].a = to_string(x * y);

	//	割り算
	x = uniform_int_distribution<>(1, 300)(rand);
	y = uniform_int_distribution<>(1, 200)(rand);
	questions[1].q = to_string(x * y) + "÷" + to_string(y) + "の答えは？";
	questions[1].a = to_string(x);

	//	複雑な式
	x = uniform_int_distribution<>(1, 1000)(rand);
	y = uniform_int_distribution<>(1, 100)(rand);
	int z = uniform_int_distribution<>(1, 100)(rand);
	int w = uniform_int_distribution<>(1, 100)(rand);
	questions[2].q =
		to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")÷" + to_string(w) + "の答えは？";
	questions[2].a = to_string(x - (y + z));

	//	累乗
	x = uniform_int_distribution<>(2, 50)(rand);
	y = uniform_int_distribution<>(2, 5)(rand);
	questions[3].q = to_string(x) + "^" + to_string(y) + "の答えは？";
	questions[3].a = to_string(static_cast<int>(pow(x, y)));

	//	三角形の面積
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 50)(rand) * 2;
	questions.push_back({"面積" + to_string(x * y / 2) + "cm^2、底辺" + to_string(y) + "cmの三角形の高さを求めよ。",to_string(x)});

	//	円錐の体積
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 50)(rand) * 3;
	questions.push_back({ "底面の半径" + to_string(x) + "cm、高さ" + to_string(y) + "cmの円錐がある。\n" +
		"この円錐の体積をXπcm^3とする。Xの値を求めよ。",to_string(x * x * y / 3) });

	cout << "[リクルート試験対策クイズ]\n";

	cout << "教科を選んでください\n1=数学\n2=国語\n";
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
			cout << "正解\n";
		}
		else
		{
			cout << "間違い！ 正解は" << e.a << "\n";
		}
	}	//	for question

	return	0;
}