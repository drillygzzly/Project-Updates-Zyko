#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"
#include "../Advanced Imgui/imguipp_v2.h"
inline int fov = 90;
inline int sens = 1000;
inline int smooth = 25;
inline int xar = 1000;
inline int yar = 1000;




static const char* Gun[]{ "NONE","AK47","LR300","MP5","SMG","TOMMY","M249","M39","SAR","S.A.P","PYTHON","REV","BOW" };
static int selectedItem1 = 0; 


static const char* Sight[]{ "NONE","HALO SIGHT","8x SIGHT","16x SIGHT","SIMPLE SIGHT" };
static int selectedItem2 = 0;


static const char* Attachment[]{ "NONE","SILENCER","MUZZLE BRAKE","MUZZLE BOOST","LASER SIGHT" };
static int selectedItem3 = 0;





inline bool checkEnabled;
inline bool HideMenu;
inline bool DemonCheck;
inline bool ProCheck;
inline bool LegitCheck;  

inline bool HipFire;
inline bool AntiAFK;
inline bool KeyBeep;
inline bool AutoLock; 
inline bool MenuColor;

inline bool checkboxJ;// I Found No CheckBox That Uses This?



namespace ui {
	void init(LPDIRECT3DDEVICE9);
	void render();
	void Theme();

	


}

namespace ui {
	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = "ZyKo Recoil";


}

namespace ui {
	inline ImVec2 screen_res{ 000, 000 };
	inline ImVec2 window_pos{ 0, 0 };
	inline ImVec2 window_size{ 240, 305};
	inline DWORD  window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
}