#pragma once
#include "constants.h"
#include "stats/statholder.h"

class Player
{
public:
	static Player* GetSingleton();

	const vector<StatHolders::StatItem*> getPlayerValues();

private:
	using Stats = constants::StatsValue;

	string getStringValueFromFloat(float x);

	float calculateValue(float p_rm, float p_r);

	string getBeast(float p_vamp, float p_were);

	int32_t getFaction(RE::Actor* &a_actor);

	vector<StatHolders::StatItem*> statList;

	string getArrowDamage(RE::PlayerCharacter* &p_player);

	string getDamage(RE::PlayerCharacter* &p_player, boolean p_left);

	string handleWeaponSpeed(RE::PlayerCharacter* &p_player, boolean p_left);

	string getXP(RE::PlayerCharacter*& p_player);

	using Lock = recursive_mutex;
	using Locker = lock_guard<Lock>;

	Player();
	Player(const Player&) = delete;
	Player(Player&&) = delete;
	~Player() = default;

	Player& operator=(const Player&) = delete;
	Player& operator=(Player&&) = delete;

	mutable Lock _lock;
};