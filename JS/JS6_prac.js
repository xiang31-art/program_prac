function text(text) {
    const textmain = "zram-generator.conf"

    if (textmain === text) {
        return "true";
    }
    return "false";
}

function run() {
    const result = text("zram-generator.conf");
    console.log(result);
}

run();