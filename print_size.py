Import("env")

def print_size(source, target, env):
    elf_path = env.subst("$BUILD_DIR/${PROGNAME}.elf")
    print("\n=== Firmware Memory Usage ===")
    env.Execute(f'arm-none-eabi-size "{elf_path}"')

env.AddPostAction("$BUILD_DIR/${PROGNAME}.elf", print_size)


print("Hello ")

for i in range(0,10):
    print("i: ", i)

print("Completed")