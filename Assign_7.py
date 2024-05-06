import nltk
from nltk.chat.util import Chat, reflections

pairs = [
    [
        r"hi|hello|hey",
        ["Hello! How can I assist you today?"]
    ],
    [
        r"what is your name?",
        ["My name is ChatBot. What's yours?"]
    ],
    [
        r"my name is (.*)",
        ["Hello %1! How can I assist you today?"]
    ],
    [
        r"how are you ?",
        ["I'm doing well, thank you! How about you?"]
    ],
    [
        r"sorry (.*)",
        ["It's okay, no worries."]
    ],
    [
        r"(.*) (good|fine)",
        ["That's great to hear! How can I assist you today?"]
    ],
    [
        r"(.*) (not good|bad)",
        ["I'm sorry to hear that. How can I assist you today?"]
    ],
    [
        r"bye|quit",
        ["Goodbye! Have a great day."]
    ]
]

# Create ChatBot
def simple_chatbot():
    print("Welcome to Simple ChatBot!")
    chatbot = Chat(pairs, reflections)
    chatbot.converse()

if __name__ == "__main__":
    simple_chatbot()
