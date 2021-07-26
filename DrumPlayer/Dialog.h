#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QDebug>
#include <QMediaPlayerControl>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_horizontalSlider_value_sliderMoved(int position);
    void on_horizontalSlider_progress_sliderMoved(int position);
    void on_pushButton_start_clicked();
    void on_pushButton_pause_clicked();
    void on_pushButton_stop_clicked();
    void on_positionChanged(qint64 position);
    void on_durationChanged(qint64 position);

   // void QMediaPlayerControl::playbackRateChanged(qreal rate);

private:
    Ui::Dialog *ui;
    QMediaPlayer *music;
};
#endif // DIALOG_H
