const HOST = "http://localhost:8000"; // e.g., "http://localhost:8000" or leave "" for same origin

let images = [];
let grouped = {};
let currentFolder = null;
let currentIndex = -1;
let currentRotation = 0;

document.addEventListener("DOMContentLoaded", () => {
	const imageList = document.getElementById("image-list");
	const imageContainer = document.getElementById("image-container");

	fetch(`${HOST}/images`)
		.then((res) => res.json())
		.then((data) => {
			images = data;
			grouped = groupByFolder(data);
			renderFolderList();
		});

	document.getElementById("prev").addEventListener("click", () => {
		if (currentIndex > 0) showImage(currentIndex - 1);
	});

	document.getElementById("next").addEventListener("click", () => {
		if (currentIndex < getCurrentImages().length - 1)
			showImage(currentIndex + 1);
	});

	document.getElementById("rotate-left").addEventListener("click", () => {
		rotateImage(-90);
	});

	document.getElementById("rotate-right").addEventListener("click", () => {
		rotateImage(90);
	});

	function groupByFolder(paths) {
		const map = {};
		for (let path of paths) {
			const parts = path.split("/").filter(Boolean);
			const folder = parts[parts.length - 2] || "root";
			if (!map[folder]) map[folder] = [];
			map[folder].push(path);
		}
		return map;
	}

	function renderFolderList() {
		currentFolder = null;
		imageList.innerHTML = "";
		for (const folder in grouped) {
			const li = document.createElement("li");
			li.textContent = folder;
			li.style.cursor = "pointer";
			li.addEventListener("click", () => {
				renderImageList(folder);
			});
			imageList.appendChild(li);
		}
	}

	function renderImageList(folder) {
		currentFolder = folder;
		imageList.innerHTML = "";

		const backBtn = document.createElement("li");
		backBtn.textContent = "⬅ Back to folders";
		backBtn.style.fontWeight = "bold";
		backBtn.style.cursor = "pointer";
		backBtn.style.marginBottom = "10px";
		backBtn.addEventListener("click", () => renderFolderList());
		imageList.appendChild(backBtn);

		grouped[folder].forEach((path, idx) => {
			const li = document.createElement("li");
			li.textContent = path.split("/").pop();
			li.style.cursor = "pointer";
			li.addEventListener("click", () => showImage(idx));
			imageList.appendChild(li);
		});
	}

	function getCurrentImages() {
		return currentFolder ? grouped[currentFolder] : [];
	}

	function showImage(index) {
		const path = getCurrentImages()[index];
		if (!path) return;
		currentIndex = index;
		currentRotation = 0;

		imageContainer.innerHTML = "";

		const img = document.createElement("img");
		img.src = `${HOST}/image?path=${encodeURIComponent(path)}`;
		img.alt = "Selected image";
		img.id = "main-image";
		img.style.transform = `rotate(0deg)`;

		imageContainer.appendChild(img);

		const downloadLink = document.getElementById("download");
		downloadLink.href = `${HOST}/image/download?path=${encodeURIComponent(
			path
		)}`;
	}

	function rotateImage(degrees) {
		const img = document.getElementById("main-image");
		if (!img) return;
		currentRotation = (currentRotation + degrees) % 360;
		img.style.transform = `rotate(${currentRotation}deg)`;
	}
});
