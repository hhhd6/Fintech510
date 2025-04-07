class MyClock24:
    def __init__(self, hours: int, minutes: int, seconds: int):
        if not (0 <= hours < 24):
            raise ValueError("小时必须在 0 到 23 之间")
        if not (0 <= minutes < 60):
            raise ValueError("分钟必须在 0 到 59 之间")
        if not (0 <= seconds < 60):
            raise ValueError("秒数必须在 0 到 59 之间")
        self._hours = hours
        self._minutes = minutes
        self._seconds = seconds

    @property
    def hours(self):
        return self._hours

    @hours.setter
    def hours(self, value):
        if not (0 <= value < 24):
            raise ValueError("小时必须在 0 到 23 之间")
        self._hours = value

    @property
    def minutes(self):
        return self._minutes

    @minutes.setter
    def minutes(self, value):
        if not (0 <= value < 60):
            raise ValueError("分钟必须在 0 到 59 之间")
        self._minutes = value

    @property
    def seconds(self):
        return self._seconds

    @seconds.setter
    def seconds(self, value):
        if not (0 <= value < 60):
            raise ValueError("秒数必须在 0 到 59 之间")
        self._seconds = value

    def tick(self):
        self._seconds += 1
        if self._seconds == 60:
            self._seconds = 0
            self._minutes += 1
        if self._minutes == 60:
            self._minutes = 0
            self._hours += 1
        if self._hours == 24:
            self._hours = 0

    def __str__(self):
        return f"{self._hours:02}:{self._minutes:02}:{self._seconds:02}"

    def __repr__(self):
        return f"{{'hours': {self._hours}, 'minutes': {self._minutes}, 'seconds': {self._seconds}}}"

    def __eq__(self, other):
        return (self._hours, self._minutes, self._seconds) == (other._hours, other._minutes, other._seconds)

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        return (self._hours, self._minutes, self._seconds) < (other._hours, other._minutes, other._seconds)

    def __le__(self, other):
        return (self._hours, self._minutes, self._seconds) <= (other._hours, other._minutes, other._seconds)

    def __gt__(self, other):
        return (self._hours, self._minutes, self._seconds) > (other._hours, other._minutes, other._seconds)

    def __ge__(self, other):
        return (self._hours, self._minutes, self._seconds) >= (other._hours, other._minutes, other._seconds)

    def __add__(self, other):
        if isinstance(other, MyClock24):
            total_seconds = self.to_seconds() + other.to_seconds()
        elif isinstance(other, int):
            total_seconds = self.to_seconds() + other
        else:
            raise TypeError("不支持的类型用于加法")

        return self.seconds_to_clock(total_seconds)

    def __sub__(self, other):
        if isinstance(other, MyClock24):
            total_seconds = self.to_seconds() - other.to_seconds()
        elif isinstance(other, int):
            total_seconds = self.to_seconds() - other
        else:
            raise TypeError("不支持的类型用于减法")

        return self.seconds_to_clock(total_seconds)

    def to_seconds(self):
        return self._hours * 3600 + self._minutes * 60 + self._seconds

    @classmethod
    def seconds_to_clock(cls, total_seconds):
        total_seconds %= 86400  # 一天有 86400 秒
        hours = total_seconds // 3600
        total_seconds %= 3600
        minutes = total_seconds // 60
        seconds = total_seconds % 60
        return cls(hours, minutes, seconds)