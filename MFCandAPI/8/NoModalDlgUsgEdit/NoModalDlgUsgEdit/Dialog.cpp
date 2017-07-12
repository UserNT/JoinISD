
#include "StdAfx.h"                 // Прекомпилируемый файл
#include "FrameWnd.h"             // Объявление класса FrameWnd
#include "Dialog.h"               // Объявление класса Dialog

// Инициализация диалога (перегрузка виртуального метода)
BOOL Dialog::OnInitDialog(void)
{
	// Вызываем метод базового класса
	CDialog::OnInitDialog();

	// Получаем указатель на однострочный редактор
	pEdit = static_cast< CEdit * >(GetDlgItem(IDC_EDIT));
	if (!pEdit)
	{
		TRACE0("\n Ошибка 5 - однострочный редактор не "
			"создан \n");
		exit(5);
	}

	// Устанавливаем длину текста (13) для элемента редактирования
	//   и вывод начального текста
	pEdit->SetLimitText(13);
	pEdit->SetWindowText(e1);

	return TRUE;
}

// ON OK: обработка закрытия диалога кнопкой "OK"
void Dialog::OnOK(void)
{
	// Вызываем метод базового класса
	CDialog::OnOK();

	// Из этого метода автоматически вызывается DoDataExchange( ),
	//   обновляющий данные из окна диалога
	UpdateData(TRUE);

	// Визуализация обновленных данных
	AfxMessageBox(static_cast< LPCTSTR >(e1));

	return;
}

// Получение данных из окна диалога (метод вызывается автоматически
//   из метода UpdateData( ))
void Dialog::DoDataExchange(CDataExchange *pDX)
{
	// Вызываем метод базового класса
	CDialog::DoDataExchange(pDX);

	// Копируем в e1 текст из однострочного редактора
	DDX_Text(pDX, IDC_EDIT, e1);

	return;
}

// Создание немодального диалога !!! Внимание, важно
BOOL Dialog::Create(void)
{
	return CDialog::Create(IDD_DIALOG_EDIT);
}
