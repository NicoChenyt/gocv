package gocv

import (
	"testing"
	"image"
)

func TestCoverWithTransparentImage(t *testing.T) {
	bg := IMRead("./images/face.jpg", 1)
	logo := IMRead("./images/gocvlogo.png", -1)
	defer bg.Close()
	defer logo.Close()

	Resize(logo, &logo, image.Pt(200, 171), 0, 0, InterpolationLinear)
	roi := bg.Region(image.Rect(60, 150, 260, 321))
	defer roi.Close()

	if !CoverWithTransparentImage(roi, logo, 1.0) {
		t.Error("Cover failed!")
	}
}
