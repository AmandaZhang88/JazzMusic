#include "Dialog.h"
#include "ui_Dialog.h"
#include <QMediaPlayer>
#include <QThread>
#include <QMediaPlaylist>
#include <QMediaPlayerControl>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    music = new QMediaPlayer(this);
    connect(music, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChanged );
    connect(music, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChanged );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_horizontalSlider_value_sliderMoved(int position)
{
     music->setVolume(position);
}

void Dialog::on_horizontalSlider_progress_sliderMoved(int position)
{
     music->setPosition(position);
}

void Dialog::on_pushButton_start_clicked()
{
    qDebug() << "pushButton_start_clicked";
    QMediaPlaylist *playlist = new QMediaPlaylist();
    qDebug() << "Recoring the music";

    playlist->addMedia(QUrl("qrc:/sounds/music/DrumSticksHitA.mp3"));
    qDebug() << "1.Drum Sticks hitted at A (la)";

    playlist->addMedia(QUrl("qrc:/sounds/music/DrumSticksHitA.mp3"));
    qDebug() << "2.Drum Sticks hitted at A (la)";

    playlist->addMedia(QUrl("qrc:/sounds/music/SmallTomDrumHit3A.mp3"));
    qDebug() << "3.Small Tom Drum Hitted at 3A (la in third range)";

    playlist->addMedia(QUrl("qrc:/sounds/music/DrumSticksHitA.mp3"));
    qDebug() << "4.Drum Sticks Hitted at A (la)";

    playlist->addMedia(QUrl("qrc:/sounds/music/DrumSticksHitA.mp3"));
    qDebug() << "5.Drum Sticks Hitted at A (la)";

    playlist->addMedia(QUrl("qrc:/sounds/music/SmallTomDrumHit3A.mp3"));
    qDebug() << "6.Small Tom Drum Hitted at 3A (la in third range)";

    playlist->addMedia(QUrl("qrc:/sounds/music/SmallTomDrumHit3A.mp3"));
    qDebug() << "7.Small Tom Drum Hitted at 3A (la in third range)";

    playlist->addMedia(QUrl("qrc:/sounds/music/DrummingJungleMusicMade.mp3"));
    qDebug() << "8.Drumming Jungle Music played with background........";

    playlist->addMedia(QUrl("qrc:/sounds/music/FloorTomDrumHit.mp3"));
    qDebug() << "9.The sounds ended.";

    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music->setPlaylist(playlist);
    music->play();

    QThread::currentThread()->sleep(1);    // rest for one
    qDebug()<<music->errorString();
}

void Dialog::on_pushButton_pause_clicked()
{
    qDebug() << "pushButton_pause_clicked";
    music->pause();
}

void Dialog::on_pushButton_stop_clicked()
{
    qDebug() << "pushButton_stop_clicked";
    music->stop();
}

void Dialog::on_positionChanged(qint64 position)
{
    ui->horizontalSlider_progress->setValue(position);
}

void Dialog::on_durationChanged(qint64 position)
{
    ui->horizontalSlider_progress->setMaximum(position);
}

