#include "WeaponTypes.h"
#include "Constants.cpp"

 std::string WeaponTypes::get_weapon_sprite(WeaponTypesEnum weaponType) 
{
	switch (weaponType) {
	case WeaponTypesEnum::Cannon:
		return FILE_PATH + "cannon.png";
	case WeaponTypesEnum::MissileLauncher:
		return "";
	case WeaponTypesEnum::Beam:
		return "";
	default:
		return "Not a valid weapon";
	}
};