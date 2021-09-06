#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Input.h"
#include "Utils.h"
#include "imgui.h"

/// Interface used by LUA scripts for creating UIs with imgui.
class LuaGUIInterface {
public:
  void Begin(const char *name) { ImGui::Begin(name); }

  void End() { ImGui::End(); }

  bool Button(const char *text) { return ImGui::Button(text); }

  bool ColorButton(const char *text, ImVec4 color) {
    return ImGui::ColorButton(text, color);
  }

  bool Checkbox(const char *text, bool enabled) {
    ImGui::Checkbox(text, &enabled);
    return enabled;
  }

  void Text(const char *text) { ImGui::Text(text); }

  void TextColored(const char *text, ImVec4 color) {
    ImGui::TextColored(color, text);
  }

  void LabelText(const char *label, const char *text) {
    ImGui::LabelText(label, text);
  }

  void LabelTextColored(const char *label, const char *text, ImVec4 color) {
    ImGui::PushStyleColor(ImGuiCol_Text, color);
    ImGui::LabelText(label, text);
    ImGui::PopStyleColor();
  }

  ImVec4 ColorPicker(const char *label, ImVec4 color) {
    ImGui::ColorPicker4(label, (float *)&color);
    return color;
  }

  int DragInt5(const char *text, int i, int step = 1, int minVal = 0,
               int maxVal = 0) {
    ImGui::DragInt(text, &i, (float)step, minVal, maxVal);
    return i;
  }

  int DragInt2(const char *text, int i) {
    ImGui::DragInt(text, &i, 1.0, 0, 0);
    return i;
  }

  //(float (LuaImguiInterface::*)(const char*, float)
  float DragFloat2(const char *text, float i) {
    ImGui::DragFloat(text, &i, 1, 0, 0);
    return i;
  }

  float DragFloat5(const char *text, float i, float step = 1, float minVal = 0,
                   float maxVal = 0) {
    ImGui::DragFloat(text, &i, step, minVal, maxVal);
    return i;
  }

  float SliderFloat(const char *label, float val, float valMin, float valMax) {
    ImGui::SliderFloat(label, &val, valMin, valMax);
    return val;
  }

  float SliderInt(const char *label, int val, int valMin, int valMax) {
    ImGui::SliderInt(label, &val, valMin, valMax);
    return val;
  }

  void Separator() { ImGui::Separator(); }

  bool CollapsingHeader(const char *text) {
    return ImGui::CollapsingHeader(text);
  }

  bool TreeNode(const char *text) { return ImGui::TreeNode(text); }

  void SetNextItemOpen() { ImGui::SetNextItemOpen(true, ImGuiCond_Once); }

  void TreePop() { ImGui::TreePop(); }

  void SameLine() { ImGui::SameLine(); }

  void BeginGroup() { ImGui::BeginGroup(); }

  void EndGroup() { ImGui::EndGroup(); }

  int ListBox(const char *label, std::vector<std::string> items, int chosen) {
    static std::vector<const char *> buffer;

    buffer.clear();

    for (auto &item : items)
      buffer.push_back(item.c_str());

    ImGui::ListBox(label, &chosen, buffer.data(), items.size(), items.size());

    return chosen;
  }

  // Key selector stuff
  void DrawButton(HKey key, HKey &clickedBtn, bool &wasClicked) {
    if (ImGui::Button(HKeyNames[key])) {
      clickedBtn = key;
      wasClicked = true;
    }
    ImGui::SameLine();
  }

  int KeySelect(const char *label, int key) {
    static int callNum = 0;

    ImGui::PushID(label);
    ImGui::BeginGroup();
    if (ImGui::Button(HKeyNames[key])) {
      ImGui::OpenPopup("Keys");
    }
    ImGui::SameLine();
    ImGui::Text(label);
    ImGui::EndGroup();

    if (ImGui::BeginPopup("Keys")) {
      HKey clickedBtn = HKey::NO_KEY;
      bool wasClicked = false;

      ImGui::BeginGroup();
      DrawButton(HKey::ESC, clickedBtn, wasClicked);
      DrawButton(HKey::F1, clickedBtn, wasClicked);
      DrawButton(HKey::F2, clickedBtn, wasClicked);
      DrawButton(HKey::F3, clickedBtn, wasClicked);
      DrawButton(HKey::F4, clickedBtn, wasClicked);
      DrawButton(HKey::F6, clickedBtn, wasClicked);
      DrawButton(HKey::F6, clickedBtn, wasClicked);
      DrawButton(HKey::F7, clickedBtn, wasClicked);
      DrawButton(HKey::F8, clickedBtn, wasClicked);
      DrawButton(HKey::F9, clickedBtn, wasClicked);
      DrawButton(HKey::F10, clickedBtn, wasClicked);
      ImGui::EndGroup();

      ImGui::BeginGroup();
      DrawButton(HKey::TILDE, clickedBtn, wasClicked);
      DrawButton(HKey::N_1, clickedBtn, wasClicked);
      DrawButton(HKey::N_2, clickedBtn, wasClicked);
      DrawButton(HKey::N_3, clickedBtn, wasClicked);
      DrawButton(HKey::N_4, clickedBtn, wasClicked);
      DrawButton(HKey::N_5, clickedBtn, wasClicked);
      DrawButton(HKey::N_6, clickedBtn, wasClicked);
      DrawButton(HKey::N_7, clickedBtn, wasClicked);
      DrawButton(HKey::N_8, clickedBtn, wasClicked);
      DrawButton(HKey::N_9, clickedBtn, wasClicked);
      DrawButton(HKey::N_0, clickedBtn, wasClicked);
      DrawButton(HKey::MINUS, clickedBtn, wasClicked);
      DrawButton(HKey::EQUAL, clickedBtn, wasClicked);
      DrawButton(HKey::BS, clickedBtn, wasClicked);
      ImGui::EndGroup();

      ImGui::BeginGroup();
      DrawButton(HKey::Tab, clickedBtn, wasClicked);
      DrawButton(HKey::Q, clickedBtn, wasClicked);
      DrawButton(HKey::W, clickedBtn, wasClicked);
      DrawButton(HKey::E, clickedBtn, wasClicked);
      DrawButton(HKey::R, clickedBtn, wasClicked);
      DrawButton(HKey::T, clickedBtn, wasClicked);
      DrawButton(HKey::Y, clickedBtn, wasClicked);
      DrawButton(HKey::U, clickedBtn, wasClicked);
      DrawButton(HKey::I, clickedBtn, wasClicked);
      DrawButton(HKey::O, clickedBtn, wasClicked);
      DrawButton(HKey::P, clickedBtn, wasClicked);
      DrawButton(HKey::LBRACKET, clickedBtn, wasClicked);
      DrawButton(HKey::RBRACKET, clickedBtn, wasClicked);
      DrawButton(HKey::ENTER, clickedBtn, wasClicked);
      ImGui::EndGroup();

      ImGui::BeginGroup();
      DrawButton(HKey::CAPS, clickedBtn, wasClicked);
      DrawButton(HKey::A, clickedBtn, wasClicked);
      DrawButton(HKey::S, clickedBtn, wasClicked);
      DrawButton(HKey::D, clickedBtn, wasClicked);
      DrawButton(HKey::F, clickedBtn, wasClicked);
      DrawButton(HKey::G, clickedBtn, wasClicked);
      DrawButton(HKey::H, clickedBtn, wasClicked);
      DrawButton(HKey::J, clickedBtn, wasClicked);
      DrawButton(HKey::K, clickedBtn, wasClicked);
      DrawButton(HKey::L, clickedBtn, wasClicked);
      DrawButton(HKey::SEMICOLON, clickedBtn, wasClicked);
      DrawButton(HKey::SINGLE_QUOTE, clickedBtn, wasClicked);
      DrawButton(HKey::BACKSLASH, clickedBtn, wasClicked);
      DrawButton(HKey::NO_KEY, clickedBtn, wasClicked);
      ImGui::EndGroup();

      ImGui::BeginGroup();
      DrawButton(HKey::LSHIFT, clickedBtn, wasClicked);
      DrawButton(HKey::Z, clickedBtn, wasClicked);
      DrawButton(HKey::X, clickedBtn, wasClicked);
      DrawButton(HKey::C, clickedBtn, wasClicked);
      DrawButton(HKey::V, clickedBtn, wasClicked);
      DrawButton(HKey::B, clickedBtn, wasClicked);
      DrawButton(HKey::N, clickedBtn, wasClicked);
      DrawButton(HKey::M, clickedBtn, wasClicked);
      DrawButton(HKey::COMMA, clickedBtn, wasClicked);
      DrawButton(HKey::DOT, clickedBtn, wasClicked);
      DrawButton(HKey::FRONTSLASH, clickedBtn, wasClicked);
      DrawButton(HKey::RSHIFT, clickedBtn, wasClicked);
      ImGui::EndGroup();

      ImGui::BeginGroup();
      DrawButton(HKey::CTRL, clickedBtn, wasClicked);
      DrawButton(HKey::ALT, clickedBtn, wasClicked);
      DrawButton(HKey::SPACE, clickedBtn, wasClicked);
      DrawButton(HKey::HOME, clickedBtn, wasClicked);
      DrawButton(HKey::INSERT, clickedBtn, wasClicked);
      DrawButton(HKey::END, clickedBtn, wasClicked);
      DrawButton(HKey::PAGE_DOWN, clickedBtn, wasClicked);
      DrawButton(HKey::PAGE_UP, clickedBtn, wasClicked);
      ImGui::EndGroup();

      if (wasClicked) {
        key = clickedBtn;
        ImGui::CloseCurrentPopup();
      }
      ImGui::EndPopup();
    }
    ImGui::PopID();
    return key;
  }
};