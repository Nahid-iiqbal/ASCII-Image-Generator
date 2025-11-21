# ASCII Image Generator

A lightweight C program that converts any image into ASCII art. This tool takes an image file as input and generates beautiful ASCII art in your terminal by mapping pixel brightness to ASCII characters.

## Features

- 🎨 Convert any image format (PNG, JPG, BMP, etc.) to ASCII art
- 📏 Adjustable output width with automatic aspect ratio preservation
- 🚀 Fast and efficient image processing using STB libraries
- 💻 Terminal-friendly output
- 🎯 Uses 66 different ASCII characters for detailed representation

### Windows

```bash
#Run Open Terminal.bat

# Run the program
./ASCIIGen.exe <image-path>
```

### Basic Usage

```bash
./ASCIIGen <image path>
```

This will display the ASCII art version of `image path` in your terminal with the original width.

### Custom Width

You can specify a custom width for the output:

```bash
./ASCIIGen <image path> -w 100
```

This will resize the output to 100 characters wide while maintaining the aspect ratio.

## How It Works

1. **Image Loading**: The program loads the image using the STB image library, which supports various formats.

2. **Resizing**: If a custom width is specified, the image is resized while maintaining aspect ratio. The height is adjusted by a factor of 0.55 to compensate for character height-to-width ratio.

3. **Grayscale Conversion**: Each pixel is converted to grayscale using the average of RGB values: `gray = (R + G + B) / 3`

4. **ASCII Mapping**: The grayscale value (0-255) is mapped to one of 66 ASCII characters, from darkest to brightest

5. **Output**: The ASCII characters are printed to the terminal, creating the final ASCII art.

## ASCII Character Set

The program uses 66 characters arranged from darkest (space) to brightest

## Technical Details

- **Language**: C
- **Dependencies**: STB libraries (header-only)
- **Memory Management**: Proper allocation and deallocation of image buffers
- **Error Handling**: Checks for file loading errors and memory allocation failures

## Tips for Best Results

- Use images with good contrast for better ASCII art
- Smaller widths (500-1000 characters) work well for detailed images
- Landscape images generally produce better results than portraits
- Try different terminal font sizes for varied effects
- Use monospace fonts in your terminal for proper alignment

## Troubleshooting

**Problem**: "Error in loading the image"
- **Solution**: Ensure the image file exists and the path is correct. Check that the image format is supported.

**Problem**: "Memory allocation failed"
- **Solution**: The image might be too large. Try using a smaller width or a smaller source image.

**Problem**: Output looks stretched or squashed
- **Solution**: The 0.55 factor adjusts for typical terminal character dimensions. You may need to adjust this value in the code for your specific terminal.

## License

This project is open source and available for personal and educational use.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests.

## Acknowledgments

- [STB Libraries](https://github.com/nothings/stb) - Single-file public domain libraries for C/C++

---

Made with ❤️ by [Nahid-iiqbal](https://github.com/Nahid-iiqbal)
