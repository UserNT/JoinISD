#ifndef Time_h
#define Time_h

namespace mayTime
{
	class TTime
	{
	public:
				
		TTime(int Hour = 0, int Minute = 0, int Second = 0);

		void SetTime(int Hour, int Minute, int Second);

		void SetHour(int Hour);
		void SetMinute(int Minute);
		void SetSecond(int Second);

		int GetHour() const;
		int GetMinute() const;
		int GetSecond() const;

		void IncrementMinute(int Count);

		void PrintTime() const;

		~TTime();
	private:
		int hour;
		int minute;
		int second;
	};
}

#endif