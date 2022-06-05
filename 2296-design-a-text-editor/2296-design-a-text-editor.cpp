class TextEditor {
public:
    string s;
    int cursor;
    TextEditor() {
        s="";
        cursor=0;
    }
    
    void addText(string text) {
        // s=s.substr(0,cursor)+text+s.substr(cursor);
        s.insert(cursor,text);
        cursor+=text.size();
    }
    
    int deleteText(int k) {
        k=min(cursor,k);
        cursor-=k;
        // s=s.substr(0,cursor)+s.substr(cursor+k);
        s.erase(cursor,k);
        return k;
    }
    
    string cursorLeft(int k) {
        cursor=max(0,cursor-k);
        int pos=max(0,cursor-10);
        return s.substr(pos,cursor-pos);
    }
    
    string cursorRight(int k) {
        cursor=min(cursor+k,int(s.size()));
        int pos=max(0,cursor-10);
        return s.substr(pos,cursor-pos);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */