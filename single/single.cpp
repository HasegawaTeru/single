#include <iostream>

class GameManager {
private:

	GameManager() {}

public:

	//　コピー・代入の禁止
	GameManager(const GameManager&) = delete;
	GameManager& operator = (const GameManager&) = delete;

	static GameManager& Instance() {
		static GameManager instance;
		return instance;
	}

	void StartGame() {
		// ゲーム開始処理
	}
};

int main() {
	//　使用例
	GameManager::Instance().StartGame();
}