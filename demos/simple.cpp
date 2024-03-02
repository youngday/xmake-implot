// Demo:   demo.cpp
// Author: Evan Pezent (evanpezent.com)
// Date:   3/26/2021

#include "App.h"

struct ImPlotDemo : App {
  using App::App;
  int i{0};
  void Update() override {
//update your data here , fps=30
    std::cout<<"update.i: "<<i++<<std::endl;
    if(i>100){
        i=0;
    }
    int bar_data[11] = {i, 1, 2, 3, 4, 5, 6, 7, 8, 9, 100};
    float x_data[1000] = {
        0,
    };
    float y_data[1000] = {
        1,
    };

    ImGui::Begin("My Window");
    if (ImPlot::BeginPlot("My Plot")) {
      ImPlot::PlotBars("My Bar Plot", bar_data, 11);
      ImPlot::PlotLine("My Line Plot", x_data, y_data, 1000);
      ImPlot::EndPlot();
    }
    ImGui::End();
  }
};

int main(int argc, char const *argv[]) {

  ImPlotDemo app("ImPlot Demo", 1920, 1080, argc, argv);
  app.Run();

  return 0;
}
