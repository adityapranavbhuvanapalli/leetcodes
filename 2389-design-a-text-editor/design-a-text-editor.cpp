class TextEditor {
public:
    string l, r;

    TextEditor() {
        l = "";
        r = "";
    }
    
    void addText(string text) {
        l += text;
    }
    
    int deleteText(int k) {
        int count = 0;
        while(l.size() && k--) {
            l.pop_back();
            count++;
        }

        return count;
    }
    
    string cursorLeft(int k) {
        while(l.size() && k--) {
            r += l.back();
            l.pop_back();
        }

        if(l.size() <= 10)
            return l;

        return l.substr(l.size() - 10);
    }
    
    string cursorRight(int k) {
        while(r.size() && k--) {
            l += r.back();
            r.pop_back();
        }

        if(l.size() <= 10)
            return l;

        return l.substr(l.size() - 10);
    }
};

/*
abcdefghijklmnopqrstuvwxyz
*/

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */