#include <iostream>

class GameManager {
private:
	/// <summary>
	/// オブジェクトを外部から生成するのを防ぐための private コンストラクタ
	/// </summary>
	GameManager() {}

public:

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
		std::cout << "Hello World!\n";
	}
};

int main() {
	//　使用例
	GameManager::Instance().StartGame();
}