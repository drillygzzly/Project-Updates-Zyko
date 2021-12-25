#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"

void ui::render() {
    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);

    /*
    Main Things I Did:
    Renamed All Checkboxes For Easier Remeberance, Also Easier To Know Which Is Which
    Add ToolTips/HelpMarkers To Help The User Understand The Function Of That Button/CheckMark
    Added A ui::Theme Took Up Most Of The Time Of Me Working On Your Source
    But It Makes It 10x Easier To Customize The GUI, Such As Rounding A Certain Item Or
    Changing The Color Of A Certain Item. It Is Very Useful In The Long Run
    I Will Add The Keybinds And The Colorpicker Soon, When I Have Freetime
    */

    ImGui::Begin(window_title, &globals.active, window_flags);
    {
        //========================================================================================================================



        if (ImGui::BeginTabBar("MAIN"))
        {
            /*
            Stuff I Did Here:
            Renamed Checkboxs To Remember Easier, And Put Code In Them Easier!
            Added ToolTips/HelpMarkers, To Help People Understand The Function Of That Button/Checkbox
            */

            if (ImGui::BeginTabItem(" Main "))
            {
                //ImGUI Here
                ImGui::Spacing();
                ImGui::Checkbox("Enabled", &checkEnabled);
                ImGui::Checkbox("Hide Menu", &HideMenu);
                ImGui::Spacing();  //space
                ImGui::Text("Weapon"); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 30, 1000), "NONE");
                ImGui::Text("Scope"); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 30, 1000), " NONE");
                ImGui::Text("Barrel"); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 30, 1000), "NONE");
                ImGui::Spacing();//space
                ImGui::Combo("Weapon", &selectedItem1, Gun, IM_ARRAYSIZE(Gun));
                ImGui::Combo("Scope", &selectedItem2, Sight, IM_ARRAYSIZE(Sight));
                ImGui::Combo("Barrel", &selectedItem3, Attachment, IM_ARRAYSIZE(Attachment));
                ImGui::Spacing(); //space
                ImGui::Checkbox("Demon Pre-set", &DemonCheck);
                HELPMARKER("WARNING: Blatant! Makes You Look And Feel Like A Demon!");
                ImGui::Checkbox("Pro Pre-set", &ProCheck);
                HELPMARKER("Makes You Look And Feel Like A Pro!");
                ImGui::Checkbox("Legit Pre-set", &LegitCheck);
                HELPMARKER("Makes You Look Like A Legit Player!");


                ImGui::EndTabItem();
            }

            /*
            Stuff I Did Here:
            Nothing Lmao
            */
            if (ImGui::BeginTabItem(" Binds "))
            {
                //ImGUI Here
                ImGui::Text("AK47");
                ImGui::Text("LR300");
                ImGui::Text("MP5");
                ImGui::Text("SMG");
                ImGui::Text("TOMMY");
                ImGui::Text("M249");
                ImGui::Text("M39");
                ImGui::Text("M92");
                ImGui::Text("SAR");
                ImGui::Text("S.A.P");
                ImGui::Text("PYTHON");
                ImGui::Text("REV");
                ImGui::Text("Bow");
                ImGui::Text("NONE");

                ImGui::EndTabItem();
            }


            /*
            Stuff I Did Here:
            Renamed Checkboxs To Remember Easier, And Put Code In Them Easier!
            */
            if (ImGui::BeginTabItem(" Misc "))
            {
                //ImGUI Here

                ImGui::Checkbox("Hipfire", &HipFire);
                ImGui::Checkbox("Anti AFK", &AntiAFK);
                ImGui::Checkbox("keybing Beep", &KeyBeep);

                ImGui::Checkbox("Auto Code Lock", &AutoLock);





                ImGui::EndTabItem();
            }

            /*
            Stuff I Did Here:
            Aligned The Text At Status, Verison, And Owner!
            */

            if (ImGui::BeginTabItem(" User "))
            {
                //ImGUI Here
                ImGui::Checkbox("Menu Color", &MenuColor);
                ImGui::Text("");
                ImGui::Text("");


                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::SliderInt("Sens", &sens, 0.f, 1000.f);
                ImGui::SliderInt("FOV", &fov, 70.f, 90.f);
                ImGui::SliderInt("Smoothness", &smooth, 0.f, 25.f);
                ImGui::TextColored(ImColor(255, 255, 255, 255), "STATUS:"); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 30, 1000), " UNDETECTED");
                ImGui::Spacing();
                ImGui::TextColored(ImColor(255, 255, 255, 255), "VERSION:"); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 30, 1000), "1.0");
                ImGui::Spacing();
                ImGui::TextColored(ImColor(255, 255, 255, 255), "OWNER:"); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 30, 1000), "  MADE BY ZyKo#1335");
                ImGui::Spacing();
                ImGui::Button("        Save settings          ");





                ImGui::EndTabItem();
            }

        }ImGui::EndTabBar();
        //=====================================================================================================================================


    }
    ImGui::End();
}

void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;

    // colors
    ImGui::StyleColorsLight();

    if (window_pos.x == 0) {
        RECT screen_rect{};
        GetWindowRect(GetDesktopWindow(), &screen_rect);
        screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
        window_pos = (screen_res - window_size) * 0.5f;

        // init images here
    }


    //Added Styling For Easier UI Changes/Color Changing!
    void ui::Theme();
    {
        ImGuiStyle& Style = ImGui::GetStyle();
        auto Color = Style.Colors;

        Style.WindowMinSize = ImVec2(240, 305); 
        Style.WindowBorderSize = 1; 

        Style.ChildRounding = 5; 
        Style.FrameRounding = 1;
        Style.ScrollbarRounding = 5;
        Style.GrabRounding = 5;
        Style.PopupRounding = 0;
        Style.WindowRounding = 5;


        Color[ImGuiCol_WindowBg] = ImColor(0, 0, 0); //WindowBackround Color

        Color[ImGuiCol_FrameBg] = ImColor(31, 31, 31, 255); //Frame Backround Color
        Color[ImGuiCol_FrameBgActive] = ImColor(41, 41, 41, 255);
        Color[ImGuiCol_FrameBgHovered] = ImColor(41, 41, 41, 255);

        Color[ImGuiCol_Button] = ImColor(255, 0, 255); //Button Color
        Color[ImGuiCol_ButtonActive] = ImColor(32, 32, 32, 255); 
        Color[ImGuiCol_ButtonHovered] = ImColor(36, 36, 36, 255);

        Color[ImGuiCol_Border] = ImColor(255, 0, 255); //Border Color
        Color[ImGuiCol_Separator] = ImColor(36, 36, 36, 255); 

        Color[ImGuiCol_ResizeGrip] = ImColor(30, 30, 30, 255); //Just In Case You Ever Do Add Resizing
        Color[ImGuiCol_ResizeGripActive] = ImColor(30, 30, 30, 255);
        Color[ImGuiCol_ResizeGripHovered] = ImColor(30, 30, 30, 255);

        Color[ImGuiCol_ChildBg] = ImColor(255, 0, 255);

        Color[ImGuiCol_ScrollbarBg] = ImColor(255, 0, 255); //Scroll Bar Color
        Color[ImGuiCol_ScrollbarGrab] = ImColor(24, 24, 24, 255);
        Color[ImGuiCol_ScrollbarGrabActive] = ImColor(255, 0, 255);
        Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);

        Color[ImGuiCol_Header] = ImColor(255, 0, 255); //Doesnt Change Anything
        Color[ImGuiCol_HeaderActive] = ImColor(255, 0, 255);
        Color[ImGuiCol_HeaderHovered] = ImColor(39, 39, 39, 255);
        
        Color[ImGuiCol_CheckMark] = ImColor(255, 0, 255); //Changes CheckMark Color
    }


}