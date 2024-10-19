import schedule
import time
import datetime

# Function to trigger the alarm
def trigger_alarm():
    print("Alarm is going off!")

# Get the current date and time
current_date = datetime.date.today()
current_time = datetime.datetime.now()

# Prompt the user to enter the alarm time
alarm_hour = int(input("Enter the hour for the alarm (24-hour format): "))
alarm_minute = int(input("Enter the minute for the alarm: "))

# Create a datetime object for the alarm time
alarm_time = current_date
alarm_time = alarm_time.replace(hour=alarm_hour, minute=alarm_minute, second=0)

# If the alarm time has already passed today, set it for tomorrow
if alarm_time < current_time:
    alarm_time += datetime.timedelta(days=1)

# Schedule the alarm
schedule.every().day.at(alarm_time.strftime("%H:%M")).do(trigger_alarm)

# Run the scheduler indefinitely
while True:
    schedule.run_pending()
    time.sleep(1)
