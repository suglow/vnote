#ifndef VINSERTIMAGEDIALOG_H
#define VINSERTIMAGEDIALOG_H

#include <QDialog>
#include <QImage>
#include <QString>
#include <QByteArray>

class QLabel;
class QLineEdit;
class VLineEdit;
class QPushButton;
class QDialogButtonBox;

class VInsertImageDialog : public QDialog
{
    Q_OBJECT
public:
    VInsertImageDialog(const QString &title, const QString &defaultImageTitle,
                       const QString &defaultPath,
                       QWidget *parent = 0);
    ~VInsertImageDialog();
    QString getImageTitleInput() const;
    QString getPathInput() const;

    void setImage(const QImage &image);
    QImage getImage() const;
    void setBrowseable(bool browseable, bool visible = false);

public slots:
    void imageDownloaded(const QByteArray &data);

private slots:
    void handleInputChanged();
    void handleBrowseBtnClicked();

private:
    void setupUI();

    QLabel *imageTitleLabel;
    VLineEdit *m_imageTitleEdit;
    QLabel *pathLabel;
    QLineEdit *pathEdit;
    QPushButton *browseBtn;
    QDialogButtonBox *m_btnBox;
    QLabel *imagePreviewLabel;

    QString title;
    QString defaultImageTitle;
    QString defaultPath;
    QImage *image;
};

#endif // VINSERTIMAGEDIALOG_H
