const alphabet1 = 'abcdefghijklmnopqrstuvwxyz'
const alphabet2 = alphabet1.toUpperCase()


function encrypt(str, n) {
    let cipher = ''
    for (let ch of str) {
        let index = undefined
        if (ch.match('^[^A-Za-z]$') !== null) {
            cipher += ch
            continue
        }
        if (ch == ch.toUpperCase()) {
            index = (alphabet2.indexOf(ch) + n) % 26
            cipher += alphabet2[index]
        }
        else if (ch == ch.toLowerCase()) {
            index = (alphabet1.indexOf(ch) + n) % 26
            cipher += alphabet1[index]
        }
    }
    return cipher
}

function decrypt(str, n) {
    let plain = ''
    for (let ch of str) {
        let index = undefined
        if (ch.match('^[^A-Za-z]$') !== null) {
            plain += ch
            continue
        }
        if (ch == ch.toUpperCase()) {
            index = ((alphabet2.indexOf(ch) - n) % 26 + 26) % 26
            plain += alphabet2[index]
        }
        else if (ch == ch.toLowerCase()) {
            index = ((alphabet1.indexOf(ch) - n) % 26 + 26) % 26
            plain += alphabet1[index]
        }
    }
    return plain
}

export { encrypt, decrypt };
