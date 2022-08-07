#include "PlayScene.h"

PlayScene::PlayScene(int levelNum) {
    this->levelIndex = levelNum;

    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/assets/Coin0001.png"));
    QString level = QString("第 %1 关").arg(levelNum);
    setWindowTitle(level);
    setWindowFlags(Qt::WindowCloseButtonHint);

    // 创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quitAction = startMenu->addAction("退出");

    connect(quitAction, &QAction::triggered, [=]() {
        this->close();
    });

    auto *backSound = new QSound(":/assets/BackButtonSound.wav", this);
    auto *flipSound = new QSound(":/assets/ConFlipSound.wav", this);
    auto *winSound = new QSound(":/assets/LevelWinSound.wav", this);

    auto *backBtn = new MyPushButton(":/assets/BackButton.png", ":/assets/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &MyPushButton::clicked, [=]() {
        backSound->play();
        QTimer::singleShot(300, this, [=]() {
            emit this->chooseSceneBack();
        });
    });

    // 显示当前关卡数
    auto *label = new QLabel;
    label->setParent(this);
    QFont qFont;
    qFont.setPointSize(20);
    QString levelStr = QString("关卡: %1").arg(this->levelIndex);
    label->setFont(qFont);
    label->setText(levelStr);
    label->setGeometry(30, this->height() - 50, 120, 50);

    DataConfig data;
    // 初始化每个关卡的二维数组
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            this->gameArray[i][j] = data.mData[this->levelIndex][i][j];
        }
    }

    // 胜利图片的显示
    auto *winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/assets/LevelCompletedDialogBg.png");
    winLabel->setParent(this);
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->move((int) ((this->width() - tmpPix.width()) * 0.5), -tmpPix.height());

    // 显示金币背景图案
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            auto *boardLabel = new QLabel;
            boardLabel->setGeometry(0, 0, 50, 50);
            boardLabel->setPixmap(QPixmap(":/assets/BoardNode.png"));
            boardLabel->setParent(this);
            boardLabel->move(57 + i * 50, 200 + j * 50);

            QString coinImage;
            if (this->gameArray[i][j] == 1) {
                coinImage = ":/assets/Coin0001.png";
            } else {
                coinImage = ":/assets/Coin0008.png";
            }
            auto *coin = new MyCoin(coinImage);
            coin->setParent(this);
            // boardLabel->setAlignment(Qt::AlignCenter);
            coin->move(59 + i * 50, 203 + j * 50);

            // 给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];

            coinBtn[i][j] = coin;

            connect(coin, &MyCoin::clicked, [=]() {
                flipSound->play();

                // 点击按钮，先将所有的按钮都禁用
                for (auto &k : this->coinBtn) {
                    for (auto &l : k) {
                        l->isWin = true;
                    }
                }

                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                // 翻转周围硬币的操作，延时翻转
                QTimer::singleShot(300, this, [=]() {
                    if (coin->posX + 1 <= 3) { // 周围的右侧硬币翻转的条件
                        coinBtn[coin->posX + 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX + 1][coin->posY] =
                                this->gameArray[coin->posX + 1][coin->posY] == 0 ? 1 : 0;

                    }
                    if (coin->posX - 1 >= 0) { // 周围左侧硬币的翻转条件
                        coinBtn[coin->posX - 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX - 1][coin->posY] =
                                this->gameArray[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
                    }
                    if (coin->posY + 1 <= 3) { // 周围下侧硬币的翻转条件
                        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] =
                                this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
                    }
                    if (coin->posY - 1 >= 0) { // 周围上侧硬币的翻转条件
                        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] =
                                this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
                    }

                    // 开启所有按钮的禁用
                    for (auto &k : this->coinBtn) {
                        for (auto &l : k) {
                            l->isWin = false;
                        }
                    }

                    // 判断是否胜利
                    this->isWin = true;
                    for (auto &i : coinBtn) {
                        for (auto &j : i) {
                            if (!j->flag) {
                                this->isWin = false;
                                break;
                            }
                        }
                    }

                    // 胜利了
                    if (this->isWin) {
                        winSound->play();
                        for (auto &i : coinBtn) {
                            for (auto &j : i) {
                                j->isWin = true;
                            }
                        }

                        // 将胜利的图片移动下来
                        auto *animation = new QPropertyAnimation(winLabel, "geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(
                                QPoint(winLabel->x(), winLabel->y()),
                                QPoint(winLabel->x() + winLabel->width(),
                                       winLabel->height())
                        ));
                        animation->setEndValue(QRect(
                                QPoint(winLabel->x(), winLabel->y() + 120),
                                QPoint(winLabel->x() + winLabel->width(),
                                       winLabel->height() + 120)
                        ));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });
            });
        }
    }
}


void PlayScene::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/assets/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    pixmap.load(":/assets/Title.png");
    pixmap = pixmap.scaled((int) (pixmap.width() * 0.5), (int) (pixmap.height() * 0.5));
    painter.drawPixmap(10, 30, pixmap.width(), pixmap.height(), pixmap);
}
