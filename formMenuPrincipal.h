#ifndef FORMMENUPRINCIPAL_H
#define FORMMENUPRINCIPAL_H

#include <QWidget>

namespace Ui {
class formMenuPrincipal;
}

class formMenuPrincipal : public QWidget
{
    Q_OBJECT

public:
    explicit formMenuPrincipal(QWidget *parent = nullptr);
    ~formMenuPrincipal();

private:
    Ui::formMenuPrincipal *ui;
};

#endif // FORMMENUPRINCIPAL_H
