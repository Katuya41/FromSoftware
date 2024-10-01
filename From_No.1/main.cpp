#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct NODE
{
    string Score;          //スコア
    string Name;           //名前
    NODE* prev = NULL;     //一個前のノード
    NODE* next = NULL;     //次のノード
};

class LIST {
private:
    NODE* Head = NULL; //先頭のノード
    NODE* Tail = NULL; //末尾のノード

public:
    //中身を先頭に挿入
    void insertFront(string _score, string _name) {
        //新しいノード作成
        NODE* NewNode;
        NewNode = new NODE;
        NewNode->Score = _score;
        NewNode->Name = _name;
        if (Head == NULL)
        {
            //要素がない場合
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //要素がある場合
            //リンクを繋ぎ変える
            NewNode->next = Head;
            Head->prev = NewNode;
            Head = NewNode;
        }
    }

    //中身を末尾に挿入
    void insertLast(string _score,string _name) {
        //新しいノードを作成
        NODE* NewNode;
        NewNode = new NODE;
        NewNode->Score = _score;
        NewNode->Name = _name;
        if (Tail == NULL)
        {
            //要素がない場合
            Tail = NewNode;
            Head = NewNode;
        }
        else
        {
            //要素がある場合
            //リンクを繋ぎ変える
            Tail->next = NewNode;
            NewNode->prev = Tail;
            Tail = NewNode;
        }
    }

    //リストの内容を表示
    void display() const {
        NODE* current = Head;
        while (current != nullptr) {
            printf("スコア: %s ,名前: %s \n", current->Score.c_str(), current->Name.c_str());
            current = current->next;
        }
    }

};

int main(void)
{
    LIST List;

    // 読み込むファイルの名前
	std::ifstream file("Scores.txt"); 
	if (!file.is_open()) {
        //開かなかった場合
		printf("ファイルが開けませんでした");
		return 0;
	}

    //受け取ったスコアと名前を入れておく変数
    string Score, Name;

    while (file >> Score >> Name) {
        // 名前とスコアを表示(確認用)
        //printf("スコア: %s ,名前: %s \n", Score, Name);
        //リストの一番末尾に入れる
        List.insertLast(Score, Name);
    }

    //リストの中身を最初から末尾まで表示
    List.display();

	return 0;
}