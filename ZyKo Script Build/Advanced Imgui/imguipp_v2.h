#pragma once
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"

#include <string>
#include <vector>
#include <functional>

//Added These Things To Make Sum Stuff Simpler

#define MAX_RGB 255.0
#define HELPMARKER(str) ImGui::SameLine(); ImGui::TextColored(ImColor(220, 190, 0, 255), "(?)"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#pragma warning(disable: 26812 26815)

namespace ImGuiPP
{

}