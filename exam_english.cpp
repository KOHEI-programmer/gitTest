#include"exam_english.h"
#include"utility.h"
using namespace std;

/*
*	//	�p�P��̖����쐬����
*/
QuestionList CreateEnglishWordExam()
{
	const struct
	{
		const char* word;		//	�p�P��
		const char* reading;	//	�ǂ�
		const char* meaning;	//	�Ӗ�
    }data[] =
    {
        {"state","�X�e�[�g","���"},
        {"business", "�r�W�l�X", "���ƁA�Ɩ�" },
        {"abstract", "�A�u�X�g���N�g", "���ۓI��" },
        {"concrete", "�R���N���[�g", "��̓I��" },
        {"digital", "�f�W�^��", "�����ŏ���`����" },
        {"analogue", "�A�i���O", "�ގ����Ă���A�ގ���" },
        {"exchange", "�G�N�X�`�F���W", "�����A���ցA�ב�" },
        {"infrastructure", "�C���t���X�g���N�`��", "�����\���A��ՂƂȂ�{�݂�ݔ�" },
        {"knowledge", "�i���b�W", "�m��" },
        {"credit", "�N���W�b�g", "�M�p" },
        {"routine", "���[�e�B��", "���܂����菇�A����" },
        {"management", "�}�l�W�����g", "�Ǘ��A�o�c" },
        {"account", "�A�J�E���g", "��v�A����" },
        {"unique", "���j�[�N", "���ɗނ����Ȃ��A���I��" },
        {"variety", "�o���G�e�B�[", "�ω��ɕx�ށA���l��" },
        {"schedule", "�X�P�W���[��", "�\��A�v��" },
        {"agenda", "�A�W�F���_", "�ۑ�A�c��" },
        {"technology", "�e�N�m���W�[", "�Ȋw�Z�p" },
        {"collaboration", "�R���{���[�V����", "���́A�������ƁA�������" },
        {"tax", "�^�b�N�X", "�ŋ�" },
        {"stock", "�X�g�b�N", "�݌ɁA����" },
        {"product", "�v���_�N�g", "���i" },
        {"booking", "�u�b�L���O", "�\��A����ւ̋L��" },
        {"weight", "�E�F�C�g", "�d��" },
        {"compliance","�R���v���C�A���X","�@��.�Љ�I�͔͂����"},
        {"receipt","���V�[�g","�̎���"},
    };

    constexpr int quizCount = 5;
    QuestionList questions;
    questions.reserve(quizCount);
    const vector<int> indices = CreateRandomIndices(size(data));

    for (int i = 0; i < quizCount; i++)
    {
        const auto& e = data[indices[i]];
        questions.push_back({ "�u" + string(e.meaning) + "�v���Ӗ�����p�P��𓚂���",e.word });
    }

    return  questions;
}