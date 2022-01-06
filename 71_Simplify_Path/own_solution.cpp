class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/') {
                if (i > 0 && path[i - 1] == '.' && (i == 1 || (i > 1 && path[i - 2] == '/'))) {
                    path = path.substr(0, i - 1) + path.substr(i + 1);
                    --i;
                } else if (i > 0 && path[i - 1] == '/') {
                    path = path.substr(0, i) + path.substr(i + 1);
                } else if (i > 1 && path[i - 1]  == '.' && path[i - 2] == '.' && (i == 2 || (i > 2 && path[i - 3] == '/'))) {
                    string path_substr = path.substr(0, i - 3);
                    int pos0 = path_substr.find_last_of('/');
                    if (pos0 != -1) {
                        path = path.substr(0, pos0) + path.substr(i);
                        i = pos0;
                    } else {
                        path = path.substr(i);
                        i -= 2;
                    }
                } else {
                    ++i;
                }
            } else {
                ++i;
            }
        }
        if (path.size() > 1 && path[path.size() - 1] == '/') {
            path = path.substr(0, path.size() - 1);
        }
        if (path.size() > 2 && path[path.size() - 1] == '.' && path[path.size() - 2] == '.' && path[path.size() - 3] == '/') {
            string path_substr = path.substr(0, path.size() - 3);
            int pos0 = path_substr.find_last_of('/');
            if (pos0 != -1) {
                path = path.substr(0, pos0);
            } else {
                path = path.substr(0, path.size() - 2);
            }
        }
        if (path.size() >= 2 && path[path.size() - 1] == '.' && path[path.size() - 2] == '/') {
            if (path.size() > 2) {
                path = path.substr(0, path.size() - 2);
            } else {
                path = path.substr(0, path.size() - 1);
            }
        }  
        if (path.size() == 0) {
            path = "/";
        }
        return path;
    }
};