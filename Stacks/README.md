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
