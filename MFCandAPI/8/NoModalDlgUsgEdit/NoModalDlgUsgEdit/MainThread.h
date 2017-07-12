

// Предотвращение возможности многократного подключения данного
//   файла
#ifndef _MainThread_h
#define _MainThread_h

// Объявление класса
class MainThread : public CWinApp
{
	// Методы

public:

	// Инициализация приложения перед запуском
	virtual BOOL InitInstance(void);
};

#endif
