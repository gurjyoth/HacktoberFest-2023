import tkinter as tk
import pyshorteners

def shorten():
    short_url = pyshorteners.Shortener().tinyurl.short(longurl_entry.get())
    shorturl_entry.delete(0, tk.END)  # Clear the entry before inserting new URL
    shorturl_entry.insert(0, short_url)

# Set up the main application window
root = tk.Tk()
root.title("URL Shortener")
root.geometry("300x150")

# Create and pack the widgets
tk.Label(root, text="Enter URL").pack()
longurl_entry = tk.Entry(root)
longurl_entry.pack()
tk.Label(root, text="Shortened URL").pack()
shorturl_entry = tk.Entry(root)
shorturl_entry.pack()
tk.Button(root, text="Shorten URL", command=shorten).pack()

root.mainloop()
