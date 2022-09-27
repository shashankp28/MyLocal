import asyncio


async def main():
    print("text0")
    await foo("text1")
    print("text2")
    return


async def foo(text):
    print(text)
    await asyncio.sleep(1)
    return

asyncio.run(main())
