#include "buscarlugar.h"
#include "ui_buscarlugar.h"
#include "InfoLugarDialog.h"
#include <QListWidgetItem>
#include <QPixmap>
#include <QPalette>
#include <QScreen>
#include <QGuiApplication>
#include "ListaSimple.h"

BuscarLugar::BuscarLugar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuscarLugar)
{
    ui->setupUi(this);

    setFixedSize(1280, 720);

    // Centrar ventana
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    move((screenGeometry.width() - width()) / 2, (screenGeometry.height() - height()) / 2);

    // Fondo
    QPixmap fondo(":/img/img/IUSH.png");
    fondo = fondo.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, fondo);
    setPalette(palette);

    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowTitle("Busqueda");

    configurarEstilos();

    // Conectar botones y enter
    connect(ui->btnRegresar, &QPushButton::clicked, this, &BuscarLugar::regresarMenuPrincipal);
    connect(ui->btnBuscar, &QPushButton::clicked, this, &BuscarLugar::realizarBusqueda);
    connect(ui->txtBuscar, &QLineEdit::returnPressed, this, &BuscarLugar::realizarBusqueda);
    ui->txtBuscar->setPlaceholderText("Buscar lugar...");
    connect(ui->listResultados, &QListWidget::itemClicked, this, &BuscarLugar::mostrarDialogo);
}

BuscarLugar::~BuscarLugar() {
    delete ui;
}

void BuscarLugar::configurarEstilos() {
    ui->txtBuscar->setStyleSheet(R"(
        QLineEdit {
            font: 16px 'Courier New';
            padding: 8px 12px;
            border-radius: 15px;
            border: 2px solid #7e3c8c;
            background-color: rgba(255,255,255,0.9);
        }
        QLineEdit:focus {
            border: 2px solid #4B0082;
            background-color: rgba(255,255,255,1);
        }
    )");

    ui->listResultados->setStyleSheet(R"(
        QListWidget {
            background-color: rgba(245,245,245,0.85);
            border-radius: 15px;
            padding: 5px;
            font: 14px 'Courier New';
        }
        QListWidget::item {
            padding: 8px;
            border-radius: 10px;
        }
        QListWidget::item:hover {
            background-color: #7e3c8c;
            color: white;
        }
        QListWidget::item:selected {
            background-color: #4B0082;
            color: white;
            font-weight: bold;
        }
    )");

    ui->btnBuscar->setStyleSheet(R"(
        QPushButton {
            font: 16px 'Courier New';
            background-color: #7e3c8c;
            color: white;
            border-radius: 15px;
            padding: 10px 25px;
        }
        QPushButton:hover { background-color: #9c27b0; font-weight: bold; }
        QPushButton:pressed { background-color: #4B0082; }
    )");

    ui->btnRegresar->setStyleSheet(R"(
        QPushButton {
            font: 14px 'Courier New';
            color: white;
            background-color: #1A356A;
            border-radius: 15px;
            padding: 10px;
            border: none;
        }
        QPushButton:hover { background-color: #8666a6; font-weight: bold; }
        QPushButton:pressed { background-color: #7B1FA2; }
    )");
}

void BuscarLugar::realizarBusqueda() {
    ui->listResultados->clear();
    QString busqueda = ui->txtBuscar->text().trimmed();
    if (busqueda.isEmpty()) return;

    // Lista simple de lugares
    ListaSimple<Lugar> lugares;

    // ADMIN1
    lugares.insertar({"Lider deporte", "ADMIN1", "101", "N/A", "Coordina actividades deportivas para los estudiantes."});
    lugares.insertar({"Dirección Bienestar Institucional", "ADMIN1", "102", "N/A", "Gestiona programas de apoyo y bienestar estudiantil."});
    lugares.insertar({"Archivo", "ADMIN1", "103", "N/A", "Almacena documentos administrativos importantes."});
    lugares.insertar({"Lider Centro Egresados", "ADMIN1", "104", "N/A", "Atiende temas relacionados con egresados de la institución."});
    lugares.insertar({"Sistema de Gestión Integral", "ADMIN1", "105", "N/A", "Administra los sistemas de gestión interna de la universidad."});
    lugares.insertar({"Lider Infraestructura", "ADMIN1", "107", "N/A", "Supervisa obras y mantenimiento de los espacios físicos."});
    lugares.insertar({"Lider Talento Humano", "ADMIN1", "108", "N/A", "Gestiona el personal y recursos humanos de la universidad."});
    lugares.insertar({"Lider Centro de Pedagogía", "ADMIN1", "205", "N/A", "Coordina proyectos académicos y pedagógicos."});
    lugares.insertar({"Lider Psicología", "ADMIN1", "208", "N/A", "Atiende programas de apoyo psicológico y bienestar mental."});
    lugares.insertar({"Lider Centro de Ext. y Proy. Social", "ADMIN1", "209", "N/A", "Gestiona proyectos de extensión y vinculación social."});
    lugares.insertar({"Oficina Pastoral", "ADMIN1", "210", "N/A", "Coordina actividades espirituales y religiosas."});
    lugares.insertar({"Lider de Centro de Internacionalización", "ADMIN1", "212", "N/A", "Gestiona convenios y movilidad internacional."});
    lugares.insertar({"Vicerrectoria Academica", "ADMIN1", "307", "N/A", "Supervisa procesos académicos y curriculares."});
    lugares.insertar({"Dirección Pastoral", "ADMIN1", "306", "N/A", "Organiza programas pastorales para la comunidad universitaria."});

    // ADMIN2
    lugares.insertar({"Gimnasio", "ADMIN2", "6to piso", "N/A", "Espacio para actividades deportivas y ejercicio físico."});
    lugares.insertar({"Escuela de ciencias creativas", "ADMIN2", "5to piso", "N/A", "Facilita clases y proyectos en áreas creativas."});
    lugares.insertar({"Escuela de Artes", "ADMIN2", "4to piso", "N/A", "Espacio para formación artística y cultural."});
    lugares.insertar({"Inglés", "ADMIN2", "3er piso", "N/A", "Clases y actividades del área de inglés."});
    lugares.insertar({"Escuela de Administración", "ADMIN2", "3er piso", "N/A", "Clases y laboratorios para administración y negocios."});
    lugares.insertar({"Sala de Docentes", "ADMIN2", "3er piso", "N/A", "Espacio para reuniones y preparación de clases por profesores."});
    lugares.insertar({"Auditorio Auxiliar", "ADMIN2", "2do piso", "N/A", "Espacio para conferencias y eventos académicos."});
    lugares.insertar({"Laboratorio de Automatización ARUS", "ADMIN2", "1er piso", "N/A", "Laboratorio de automatización y robótica."});

    // ADMIN3
    lugares.insertar({"Tesoreria/Recaudo", "ADMIN3", "1er piso", "N/A", "Gestiona pagos, recaudos y tesorería."});
    lugares.insertar({"Mercadeo", "ADMIN3", "1er piso", "N/A", "Se encarga de marketing y comunicación institucional."});
    lugares.insertar({"Atención al usuario", "ADMIN3", "1er piso", "N/A", "Brinda información y asistencia a estudiantes y visitantes."});
    lugares.insertar({"Permanencia y graduación con calidad", "ADMIN3", "1er piso", "N/A", "Apoya procesos de graduación y seguimiento académico."});
    lugares.insertar({"Gestión profesoral", "ADMIN3", "1er piso", "N/A", "Administra temas de contratación y gestión de docentes."});
    lugares.insertar({"Facturación y Cartera", "ADMIN3", "1er piso", "N/A", "Encargado de facturación y cobros de la universidad."});
    lugares.insertar({"Admisiones y Registros", "ADMIN3", "1er piso", "N/A", "Gestiona el proceso de admisiones y registro académico."});
    lugares.insertar({"Centro documental", "ADMIN3", "1er piso", "N/A", "Archivo y custodia de documentos institucionales."});
    lugares.insertar({"Infraestructura Fisica", "ADMIN3", "2do piso", "N/A", "Supervisión de infraestructura y mantenimiento físico."});
    lugares.insertar({"Contabilidad Institucional", "ADMIN3", "2do piso", "N/A", "Gestiona contabilidad y reportes financieros."});
    lugares.insertar({"Adquisición de Bienes y Servicios", "ADMIN3", "2do piso", "N/A", "Se encarga de compras y adquisiciones de la universidad."});
    lugares.insertar({"Contabilidad Liceo", "ADMIN3", "2do piso", "N/A", "Lleva la contabilidad del área del liceo."});
    lugares.insertar({"Taleo Humano", "ADMIN3", "2do piso", "N/A", "Gestiona el talento humano y nómina."});
    lugares.insertar({"Contabilidad Institución Universitaria", "ADMIN3", "2do piso", "N/A", "Contabilidad general de la institución universitaria."});
    lugares.insertar({"Talento Humano", "ADMIN3", "2do piso", "N/A", "Administra personal y desarrollo profesional."});
    lugares.insertar({"Activos Fijos", "ADMIN3", "2do piso", "N/A", "Registro y control de bienes y activos de la universidad."});
    lugares.insertar({"Causación", "ADMIN3", "2do piso", "N/A", "Control de causaciones contables y financieras."});
    lugares.insertar({"Contabilidad Presupuesto", "ADMIN3", "2do piso", "N/A", "Gestión y planificación del presupuesto institucional."});
    lugares.insertar({"Tesorería / Pagos", "ADMIN3", "2do piso", "N/A", "Procesamiento de pagos y tesorería."});
    lugares.insertar({"Centro Documental Financiero", "ADMIN3", "2do piso", "N/A", "Archivo de documentos financieros y contables."});
    lugares.insertar({"Vicerrectoría Administrativa y Financiera", "ADMIN3", "2do piso", "N/A", "Coordina áreas administrativas y financieras."});

    // TEC
    lugares.insertar({"Cuarto Fotografico", "TEC", "301", "N/A", "Espacio destinado a fotografía y material visual."});
    lugares.insertar({"Laboratorio de simulación", "TEC", "303", "N/A", "Laboratorio de simulaciones técnicas y prácticas."});
    lugares.insertar({"Archivo", "TEC", "304", "N/A", "Almacén de documentos y registros del área técnica."});
    lugares.insertar({"Laboratorio Automatización", "TEC", "305", "N/A", "Laboratorio de automatización industrial y robótica."});
    lugares.insertar({"Laboratorio de Electronica", "TEC", "306", "N/A", "Laboratorio de electrónica y circuitos."});
    lugares.insertar({"Laboratorio de STEAN", "TEC", "307", "N/A", "Laboratorio de STEAN para proyectos de ciencia y tecnología."});
    lugares.insertar({"Laboratorio de STEAM", "TEC", "308", "N/A", "Laboratorio de STEAM para proyectos educativos y tecnológicos."});
    lugares.insertar({"Centro de Virtualidad", "TEC", "404", "N/A", "Espacio de recursos y aulas virtuales."});
    lugares.insertar({"Laboratorio y Fabricación de Software", "TEC", "405", "N/A", "Laboratorio para desarrollo y pruebas de software."});
    lugares.insertar({"Infraestructura y Desarrollo Tec.", "TEC", "406", "N/A", "Gestión de infraestructura y desarrollo tecnológico."});
    lugares.insertar({"Laboratorio de Software", "TEC", "509", "N/A", "Laboratorio de software, desarrollo y pruebas."});
    lugares.insertar({"Laboratorio de Software", "TEC", "510", "N/A", "Laboratorio de software, desarrollo y pruebas."});

    // ACA1
    lugares.insertar({"Centro de Conciliación", "ACA1", "1er piso", "N/A", "Ofrece servicios de conciliación y resolución de conflictos."});
    lugares.insertar({"Atención al Usuario", "ACA1", "1er piso", "N/A", "Atiende dudas y solicitudes de estudiantes y personal."});
    lugares.insertar({"Consultorio Jurídico", "ACA1", "1er piso", "N/A", "Asesoría legal y jurídica a la comunidad universitaria."});
    lugares.insertar({"Sala de Oralidad", "ACA1", "1er piso", "N/A", "Espacio para juicios simulados y prácticas de oralidad."});
    lugares.insertar({"DEIA", "ACA1", "103", "N/A", "Departamento de equidad e inclusión académica."});
    lugares.insertar({"Sala de Descanso", "ACA1", "102", "N/A", "Espacio para descanso y recreación de estudiantes."});

    // ACA2
    lugares.insertar({"Biblioteca", "ACA2", "2do piso", "N/A", "Préstamo de libros y consulta académica."});
    lugares.insertar({"Salon de Videojuegos Inder", "ACA2", "201", "N/A", "Espacio recreativo con videojuegos para estudiantes."});

    // Filtrar y mostrar resultados
    NodoSimple<Lugar>* actual = lugares.getCabeza();
    while(actual != nullptr) {
        const Lugar &l = actual->dato;
        if(l.nombre.contains(busqueda, Qt::CaseInsensitive)) {
            QListWidgetItem *item = new QListWidgetItem(l.nombre);
            item->setData(Qt::UserRole, l.bloque);
            item->setData(Qt::UserRole + 1, l.piso);
            item->setData(Qt::UserRole + 2, l.correo);
            item->setData(Qt::UserRole + 3, l.descripcion);
            ui->listResultados->addItem(item);
        }
        actual = actual->siguiente;
    }
}

void BuscarLugar::mostrarDialogo(QListWidgetItem *item) {
    InfoLugarDialog *dialogo = new InfoLugarDialog(this);
    dialogo->setInfo(
        item->text(),
        item->data(Qt::UserRole).toString(),
        item->data(Qt::UserRole + 1).toString(),
        item->data(Qt::UserRole + 2).toString(),
        item->data(Qt::UserRole + 3).toString()
        );
    dialogo->exec();
}

void BuscarLugar::regresarMenuPrincipal() {
    QWidget *parent = this->parentWidget();
    if(parent) parent->show();
    this->close();
}
