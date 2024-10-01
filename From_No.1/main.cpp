#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct NODE
{
    string Score;          //�X�R�A
    string Name;           //���O
    NODE* prev = NULL;     //��O�̃m�[�h
    NODE* next = NULL;     //���̃m�[�h
};

class LIST {
private:
    NODE* Head = NULL; //�擪�̃m�[�h
    NODE* Tail = NULL; //�����̃m�[�h

public:
    //���g��擪�ɑ}��
    void insertFront(string _score, string _name) {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        NewNode = new NODE;
        NewNode->Score = _score;
        NewNode->Name = _name;
        if (Head == NULL)
        {
            //�v�f���Ȃ��ꍇ
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //�v�f������ꍇ
            //�����N���q���ς���
            NewNode->next = Head;
            Head->prev = NewNode;
            Head = NewNode;
        }
    }

    //���g�𖖔��ɑ}��
    void insertLast(string _score,string _name) {
        //�V�����m�[�h���쐬
        NODE* NewNode;
        NewNode = new NODE;
        NewNode->Score = _score;
        NewNode->Name = _name;
        if (Tail == NULL)
        {
            //�v�f���Ȃ��ꍇ
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //�v�f������ꍇ
            //�����N���q���ς���
            Tail->next = NewNode;
            NewNode->prev = Tail;
            Tail = NewNode;
        }
    }

    //���X�g�̓��e��\��
    void display() const {
        NODE* current = Head;
        while (current != nullptr) {
            printf("�X�R�A: %s ,���O: %s \n", current->Score.c_str(), current->Name.c_str());
            current = current->next;
        }
    }

};

int main(void)
{
    LIST List;

    // �ǂݍ��ރt�@�C���̖��O
	std::ifstream file("Scores.txt"); 
	if (!file.is_open()) {
        //�J���Ȃ������ꍇ
		printf("�t�@�C�����J���܂���ł���");
		return 0;
	}

    //�󂯎�����X�R�A�Ɩ��O�����Ă����ϐ�
    string Score, Name;

    while (file >> Score >> Name) {
        // ���O�ƃX�R�A��\��(�m�F�p)
        //printf("�X�R�A: %s ,���O: %s \n", Score, Name);
        //���X�g�̈�Ԗ����ɓ����
        List.insertLast(Score, Name);
    }

    //���X�g�̒��g���ŏ����疖���܂ŕ\��
    List.display();

	return 0;
}