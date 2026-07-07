#include <iostream>
#include <conio.h>	// _getch() を使うために必要

class GameManager {
private:
	/// <summary>
	/// オブジェクトを外部から生成するのを防ぐための private コンストラクタ
	/// </summary>
	GameManager() {}

public:

	enum Scene
	{
		Title,
		Game,
		GameOver,
		GameClear
	};

	Scene GameScene = Title;
	
	int random = 0;

	/// <summary>
	/// 別のオブジェクトのコピーを禁止するためのコピーコンストラクタ
	/// </summary>
	GameManager(const GameManager&) = delete;
	/// <summary>
	/// 別のオブジェクトのコピーを禁止するためのコピーコンストラクタ
	/// </summary>
	GameManager& operator=(const GameManager&) = delete;

	/// <summary>
	/// スレッドセーフな、GameManager の唯一のオブジェクトを返すことができる
	/// </summary>
	/// <returns></returns>
	static GameManager& Instance() {
		static GameManager instance;
		return instance;
	}

	void StartGame()
	{
		switch (GameScene)
		{
		case Title:
			std::cout << "Title Scene" << std::endl;
			std::cout << "何かキーを押してください。" << std::endl;
			//　何らかの入力を受け取る
			(void)_getch();
			GameScene = Game;

			return StartGame();
			
			break;

		case Game:
			std::cout << "Game Scene" << std::endl;
			std::cout << "何かキーを押してください。" << std::endl;

			(void)_getch();
			//　ゲームオーバーか、ゲームクリアかをランダムに決定する
			random = rand() % 2;
			if (random == 0)
			{
				GameScene = GameOver;
			}
			else if (random == 1)
			{
				GameScene = GameClear;
			}

			return StartGame();

			break;

		case GameOver:
			std::cout << "GameOver Scene" << std::endl;
			std::cout << "何かキーを押してください。" << std::endl;

			(void)_getch();
			GameScene = Title;

			return StartGame();

			break;

		case GameClear:
			std::cout << "GameClear Scene" << std::endl;
			std::cout << "何かキーを押してください。" << std::endl;

			(void)_getch();
			GameScene = Title;

			return StartGame();

			break;
		}
	}
};

int main() 
{
	GameManager::Instance().StartGame();
}