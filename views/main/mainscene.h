#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include <QSound>
#include "../chooseLevel/ChooseLevelScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow {
Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);

    ~MainScene() override;

    // 重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent *) override;

    ChooseLevelScene *chooseScene = nullptr;
private:
    Ui::MainScene *ui;
};

#endif // MAIN_SCENE_H
