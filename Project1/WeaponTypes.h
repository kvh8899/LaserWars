#pragma once
#include <string>
class WeaponTypes
{
public:
	enum WeaponTypesEnum { 
		Cannon = 0,
		MissileLauncher = 1,
		Beam = 2 
	};

	static std::string get_weapon_sprite(WeaponTypesEnum weaponType);
};
