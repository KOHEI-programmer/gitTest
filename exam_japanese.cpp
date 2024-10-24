#include"exam_japanese.h"
using namespace std;

//	漢字の読み取り問題を作成する

QuestionList CreateKanjiExam()
{
	static const struct
	{
		const char* Kanji;		//	漢字
		const char* reading;	//	読み
		const char* meaning;	//	意味
	}data[] =
	{
		{"市井", "しせい", "人が集まって暮らすところ、町" },
		{"捺印", "なついん", "(署名と共に)印鑑を押すこと" },
		{"相殺", "そうさつ", "足し引きの結果、差がなくなること" },
		{"凡例", "はんれい", "本や図表のはじめに、使い方や約束事を箇条書きにしたもの" },
		{"約定", "やくじょう", "約束して決めること、約束" },
	};

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	for (int i = 0; i < quizCount; i++)
	{
		const auto& e = data[i];
		questions.push_back({ "「" + string(e.Kanji) + "」の読みをひらがなで答えよ",e.reading });

	}
	return	questions;

}
