# HTML Angle Bracket Validator

---

## How It Works

1. **Read the HTML File**:
   - The entire file is read into a string using `std::istreambuf_iterator`.

2. **Validate Brackets**:
   - Iterate through the string character by character.
   - Push `<` onto the stack.
   - Pop from the stack when `>` is encountered.
   - If the stack is empty at the end, all brackets are matched.

---

## Code 

```C++
bool isHTMLValid(const string& text) {
    Stack<char> stack;

    for (char ch : text) {
        if (ch == '<') stack.push(ch);
        else if (ch == '>') {
            if (stack.empty()) return false;
            stack.pop();
        }
    }
    return stack.empty();
}
```

---

## Example Input

`wget ict.gctaa.com`

```html
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<base id="baseHref" href="https://ict.gctaa.net">
<link rel="icon" href="https://ict.gctaa.net/favicon.png">
<title>Computer Science and Web Development at ACC</title>
<style>
@import url(css/index.css);
</style>
<script src="js/index.js"></script>
<script>
window.onload = setValidationLinks;
</script>
</head>

.....

</main>

<footer>
<p>
<a href="http://www.gnu.org/copyleft/copyleft.html">&copy;</a> 2025
Arlington Tech Governor's Career and Technical Academy.
</p><p>
Powered by <a href="http://www.fsf.org">Free Software</a>.
</p>
</footer>

</body>
</html>
```


## Handling Self-Closing Tags

- **New Feature**: Now supports self-closing tags like `<br />`, `<img />`, and `<a />`.
- **How It Works**:
  - Self-closing tags are detected by checking if the tag ends with `/>`.
  - These tags are skipped during validation (not pushed onto the stack).
- **Example**:
  - `<img src="image.png" />` → Valid (skipped).
  - `<a href="#" />` → Valid (skipped).

```C++
string extractTagName(const string& tag) {
    if (tag.empty() || tag[0] != '<') return ""; // Not a valid tag

    size_t end = tag.find_first_of(" />");
    if (end == string::npos) return ""; // Invalid tag format

    string tagName = tag.substr(1, end - 1); // Extract the tag name
    if (tagName[0] == '/') {
        tagName = tagName.substr(1); // Remove '/' for closing tags
    }
    return tagName;
}

// Function to check if all tags are properly matched
bool isHTMLValid(const string& text) {
    Stack<string> stack;
    size_t pos = 0;

    while (pos < text.length()) {
        size_t openBracket = text.find('<', pos);
        if (openBracket == string::npos) break; // No more tags

        size_t closeBracket = text.find('>', openBracket);
        if (closeBracket == string::npos) return false; // Unmatched '<'

        string tag = text.substr(openBracket, closeBracket - openBracket + 1);
        string tagName = extractTagName(tag);

        if (tagName.empty()) return false; // Invalid tag

        // Check if it's a self-closing tag (ends with "/>")
        if (tag.length() >= 2 && tag[tag.length() - 2] == '/' && tag[tag.length() - 1] == '>') {
            // Self-closing tag: skip it (do not push onto the stack)
            pos = closeBracket + 1;
            continue;
        }

        if (tag[1] != '/') {
            // Opening tag: push onto the stack
            stack.push(tagName);
        } else {
            // Closing tag: check if it matches the top of the stack
            if (stack.empty() || stack.top() != tagName) {
                return false; // Mismatched tag
            }
            stack.pop();
        }

        pos = closeBracket + 1; // Move to the next character after '>'
    }

    return stack.empty(); // All tags must be matched
}
```

---

## Limitations and Future Work

- **Comments and Scripts**: Not yet handled.
- **Error Reporting**: Can be improved to show specific mismatches.
- **Attributes**: Fully supported, but complex attribute parsing is not implemented.
```