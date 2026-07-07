#include <iostream>
#include <conio.h>

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

			(void)_getch();
			GameScene = Game;

			return StartGame();
			
			break;

		case Game:
			std::cout << "Game Scene" << std::endl;
			std::cout << "何かキーを押してください。" << std::endl;

			(void)_getch();
			GameScene = GameClear;

			return StartGame();

			break;

		case GameOver:
			std::cout << "GameOver Scene" << std::endl;
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